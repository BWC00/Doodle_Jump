#ifndef DOODLE_JUMP_LOGIC_SIMPLEENEMY_H
#define DOODLE_JUMP_LOGIC_SIMPLEENEMY_H

#include "Bonus.h"

namespace logic {
    class SimpleEnemy final : public logic::Bonus {
    public:
	    SimpleEnemy(double x, double y);
	    ~SimpleEnemy() override = default;
	    void Jumped(logic::Player*) override;
	    bool Collided(logic::Player*) override;
    };
}

#endif