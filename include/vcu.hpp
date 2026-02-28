#pragma once
#include "sc_s1.hpp"
#include "sc_s2.hpp"
#include <cstdint>
#include <string>

class VirtualControlUnit {
	public:
		struct StatesSC {
			std::string s1_st;
			std::string s2_st;
		};
		explicit VirtualControlUnit(uint8_t node);
		void send_event(const Event& ev);
		StatesSC get_sc_states();
	private:
		uint8_t node_;
		SupervisorS1 s1_;
		SupervisorS2 s2_;
};
