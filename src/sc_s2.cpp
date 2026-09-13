#include "sc_s2.hpp"
#include <iostream>

SupervisorS2::SupervisorS2(uint8_t node) : Supervisor(node) {
	this->init_super();
}

void SupervisorS2::init_super() {
	std::cout<<"Node "<<(int)this->node_<<" - S1 Created"<<"\n";
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

