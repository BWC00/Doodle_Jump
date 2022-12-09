

#ifndef DOODLE_JUMP_LOGIC_JETPACK_H
#define DOODLE_JUMP_LOGIC_JETPACK_H

#include "Bonus.h"

namespace logic {
    class Jetpack final : public logic::Bonus {
    public:
	    Jetpack(double x, double y);
	    ~Jetpack() override = default;
    	void Jumped(logic::Player*) override;
    	bool Collided(logic::Player*) override;
	protected:
		double _boost;
    };
}

#endif
