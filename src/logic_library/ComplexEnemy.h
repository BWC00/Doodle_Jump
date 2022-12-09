#ifndef DOODLE_JUMP_LOGIC_COMPLEXENEMY_H
#define DOODLE_JUMP_LOGIC_COMPLEXENEMY_H

#include "Bonus.h"

namespace logic {
    class ComplexEnemy final : public logic::Bonus {
    public:
	    ComplexEnemy(double x, double y);
	    ~ComplexEnemy() override = default;
	    void Jumped(logic::Player*) override;
	    bool Collided(logic::Player*) override;
	    int getHP() const;
	private:
		int _HP;
    };
}

#endif