#ifndef DOODLE_JUMP_LOGIC_SPIKE_H
#define DOODLE_JUMP_LOGIC_SPIKE_H

#include "Bonus.h"

namespace logic {
    class Spike final : public logic::Bonus {
    public:
	    Spike(double x, double y);
	    ~Spike() override = default;
	    void Jumped(logic::Player*) override;
	    bool Collided(logic::Player*) override;
    };
}

#endif