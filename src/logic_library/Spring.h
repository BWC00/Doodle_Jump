

#ifndef DOODLE_JUMP_LOGIC_SPRING_H
#define DOODLE_JUMP_LOGIC_SPRING_H

#include "Bonus.h"

namespace logic {
    class Spring final : public logic::Bonus {
    public:
	    Spring(double x, double y);
	    ~Spring() override = default;
	    void Jumped(logic::Player*) override;
	    bool Collided(logic::Player*) override;
	protected:
		double _boost;
    };
}

#endif