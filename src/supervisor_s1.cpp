#include <supervisor_s1.hpp>

#include <iostream>

SupervisorS1::SupervisorS1(uint8_t node) : node_(node) {
	std::cout<<"super1 created, node "<<(int)node_<<"\n";
	Event ev;
	ev.node = 1;
	this->state_transition(ev);
}

void SupervisorS1::state_transition(const Event& ev){

}

int main(int argc, char* argv[]){
	uint8_t node{1};
	SupervisorS1 s1(node);
	return 0;
}
