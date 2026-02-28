#include "supervisor_s1.hpp"

#include <iostream>

SupervisorS1::SupervisorS1(uint8_t node) : node_(node) {
	std::cout<<"super1 created, node "<<(int)node_<<"\n";
	Event ev;
	ev.node = 1;
	ev.id = EvId::e1;
	this->state_transition(ev);
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

int main(int argc, char* argv[]){
	uint8_t node{1};
	SupervisorS1 s1(node);
	return 0;
}
