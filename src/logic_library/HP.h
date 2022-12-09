#ifndef DOODLE_JUMP_LOGIC_HP_H
#define DOODLE_JUMP_LOGIC_HP_H

#include "Bonus.h"

namespace logic {
    class HP final : public logic::Bonus {
    public:
	    HP(double x, double y);
	    ~HP() override = default;
	    void Jumped(logic::Player*) override;
	    bool Collided(logic::Player*) override;
    };
}

#endif