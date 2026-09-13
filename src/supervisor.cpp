#include "supervisor.hpp"
#include <iostream>

Supervisor::Supervisor(uint8_t node) : node_(node) {}

std::string Supervisor::get_state_name(const State st) const {
        switch (st) {
                case State::qs1: return "qs1";
                case State::qs2: return "qs2";
        }
        return "unknown";
}

std::string Supervisor::get_state() const {
        return this->get_state_name(this->st_);
}

void Supervisor::send_event(const Event& ev) {
        this->state_transition(ev);
}
