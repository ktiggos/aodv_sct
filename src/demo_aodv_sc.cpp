#include "vcu.hpp"
#include "sc_s1.hpp"
#include "sc_s2.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

typedef VirtualControlUnit VCU;

int main(int argc, char* argv[]) {
	VCU units[3] = {VCU(1), VCU(2), VCU(3)};

	std::ifstream file("data/event_seq.json");

	if(!file){
		throw::std::runtime_error("Cannot open json file.");
	};

	nlohmann::json ev_seq;
	file >> ev_seq;

	return 0;
}
