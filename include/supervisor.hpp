#pragma once
#include "events.hpp"
#include <string>

class Supervisor {
    public:
        explicit Supervisor(uint8_t node);

        std::string get_state() const;
        void send_event(const Event& ev);
    protected:
        enum class State : uint8_t {
                        qs1,
                        qs2
        };
        std::string get_state_name(const State st) const;
        
        virtual void state_transition(const Event& ev);
        virtual void init_super();

        uint8_t node_;
        State st_{State::qs1};
};