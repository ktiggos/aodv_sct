#include "sc_s1.hpp"
#include <iostream>

SupervisorS1::SupervisorS1(uint8_t node) : node_(node) {
	std::cout<<"Node "<<(int)node_<<" - S1 Created"<<"\n";
}

void SupervisorS1::state_transition(const Event& ev){
	switch(this->st_){
		case(State::qs1):
			if(ev.id == EvId::e1){
				this->st_ = State::qs2;
			};

			if(ev.node != this->node_){
				if(ev.id == EvId::e4 || ev.id == EvId::e6){
					this->st_ = State::qs1;
				};
			};
			break;
		case(State::qs2):
			if(ev.node != this->node_){
				if(ev.id == EvId::e1){
					this->st_ = State::qs2;
				} else if(ev.id == EvId::e4 || ev.id == EvId::e6){
					this->st_ = State::qs1;
				};
			};
			break;
	}
}

std::string SupervisorS1::get_state_name(const State st) const {
	switch (st) {
        	case State::qs1: return "qs1";
        	case State::qs2: return "qs2";
    	}
    	return "unknown";
}

std::string SupervisorS1::get_state() const {
	return this->get_state_name(this->st_);
}

void SupervisorS1::send_event(const Event& ev) {
        this->state_transition(ev);
}

