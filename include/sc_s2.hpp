#pragma once
#include "events.hpp"
#include <string>
#include "supervisor.hpp"

class SupervisorS2 : public Supervisor {
    public:
        explicit SupervisorS2(uint8_t node);
    private:
        void state_transition(const Event& ev) override;
        void init_super() override;
};
