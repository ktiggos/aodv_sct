#include "sc_s2.hpp"
#include <iostream>

SupervisorS2::SupervisorS2(uint8_t node) : node_(node) {
        std::cout<<"Node "<<(int)node_<<" - S2 Created"<<"\n";
}

void SupervisorS2::state_transition(const Event& ev){
        switch(this->st_){
                case(State::qs1):
                        if(ev.node != this->node_){
                                if(ev.id == EvId::e4 || ev.id == EvId::e6){
                                        this->st_ = State::qs2;
                                };
                        };
                        break;
                case(State::qs2):
                        if(ev.node == this->node_){
				if(ev.id == EvId::e2){
					this->st_ = State::qs1;
				};
                        } else {
				if(ev.id == EvId::e4 || ev.id == EvId::e6){
					this->st_ = State::qs2;
				};
			};
                        break;
        }
}

std::string SupervisorS2::get_state_name(const State st) const {
        switch (st) {
                case State::qs1: return "qs1";
                case State::qs2: return "qs2";
        }
        return "unknown";
}

std::string SupervisorS2::get_state() const {
        return this->get_state_name(this->st_);
}

void SupervisorS2::send_event(const Event& ev) {
        this->state_transition(ev);
}

