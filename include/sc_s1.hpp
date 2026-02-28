#pragma once
#include "events.hpp"
#include <string>

class SupervisorS1 {
	public:
		explicit SupervisorS1(uint8_t node);
		std::string getState() const;
	private:
		enum class State : uint8_t {
                        qs1,
                        qs2
                };

		void state_transition(const Event& ev);
		std::string getStateName(const State st) const;

		uint8_t node_;
		State st_{State::qs1};
};
