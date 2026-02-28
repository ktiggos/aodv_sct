#include "vcu.hpp"

VirtualControlUnit::VirtualControlUnit(uint8_t node) 
	: node_(node), s1_(node_), s2_(node_)
{}

void VirtualControlUnit::send_event(const Event& ev) {
	this->s1_.send_event(ev);
	this->s2_.send_event(ev);
}

VirtualControlUnit::StatesSC VirtualControlUnit::get_sc_states() {
	return StatesSC{
		this->s1_.get_state(),
		this->s2_.get_state()
	};
}
