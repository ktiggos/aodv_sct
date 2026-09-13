#include "sc_s1.hpp"
#include <iostream>

SupervisorS1::SupervisorS1(uint8_t node) : Supervisor(node) {
	this->init_super();
}

void SupervisorS1::init_super() {
	std::cout<<"Node "<<(int)this->node_<<" - S1 Created"<<"\n";
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

