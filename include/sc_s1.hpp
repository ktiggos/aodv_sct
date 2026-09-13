#pragma once
#include "events.hpp"
#include <string>
#include "supervisor.hpp"

class SupervisorS1 : public Supervisor {
    public:
        explicit SupervisorS1(uint8_t node);
    private:
        void state_transition(const Event& ev) override;
        void init_super() override;
};