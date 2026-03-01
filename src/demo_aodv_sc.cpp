#include "vcu.hpp"

#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include <nlohmann/json.hpp>
#include <filesystem>

using json = nlohmann::json;
using VCU  = VirtualControlUnit;

static EvId to_evid(int v)
{
    switch (v) {
        case 1: return EvId::e1;
        case 2: return EvId::e2;
        case 4: return EvId::e4;
        case 6: return EvId::e6;
        default:
            throw std::runtime_error("Unknown evid value: " + std::to_string(v));
    }
}

static Event get_event(const json& ev_json)
{
    uint8_t node = ev_json.at("node").get<uint8_t>();
    int evid_i   = ev_json.at("evid").get<int>();
    return { node, to_evid(evid_i) };
}

static json event_to_json_or_null(const Event* ev)
{
    if (!ev) return nullptr;
    return json{
        {"node", ev->node},
        {"evid", static_cast<int>(ev->id)}
    };
}

static json states_snapshot(const std::array<VCU,3>& units)
{
    json states = json::object();

    for (std::size_t i = 0; i < units.size(); ++i) {
        const auto st = units[i].get_sc_states();
        const int node_id = static_cast<int>(i + 1);

        states[std::to_string(node_id)] = {
            {"S1", st.s1_st},
            {"S2", st.s2_st}
        };
    }

    return states;
}

int main()
{
    std::array<VCU,3> units = { VCU(1), VCU(2), VCU(3) };

    std::ifstream file("data/event_seq.json");
    if (!file) {
        throw std::runtime_error("Cannot open json file: data/event_seq.json");
    }

    json ev_seq;
    file >> ev_seq;

    if (!ev_seq.contains("seq") || !ev_seq["seq"].is_array()) {
        throw std::runtime_error("Invalid JSON: missing array key 'seq'");
    }

    json out;
    out["trace"] = json::array();

    {
        json step;
        step["k"] = 0;
        step["event"] = nullptr;
        step["states"] = states_snapshot(units);
        out["trace"].push_back(step);
    }

    std::size_t k = 0;

    for (const auto& ev_json : ev_seq["seq"]) {
        ++k;

        const Event ev = get_event(ev_json);

        for (auto& u : units) {
            u.send_event(ev);
        }

        json step;
        step["k"] = k;
        step["event"] = event_to_json_or_null(&ev);
        step["states"] = states_snapshot(units);
        out["trace"].push_back(step);
    }

    std::filesystem::create_directories("out");

    std::ofstream out_file("out/state_trace.json");
    if (!out_file) {
        throw std::runtime_error("Cannot open output file: out/state_trace.json");
    }

    out_file << out.dump(4);

    return 0;
}
