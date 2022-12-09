#include "ComplexEnemy.h"
#include "Player.h"
#include "Random.h"

logic::ComplexEnemy::ComplexEnemy(double x, double y) : logic::Bonus(x,y) {
    // _boost = 4;
    _hitBox.first = 0.1298245;
    _hitBox.second = 0.13;
    _position.first = x+0.185-(_hitBox.first/2.0);
    _position.second = y+_hitBox.second;
    _HP = logic::Random::uniformInt(3,5);
}

void logic::ComplexEnemy::Jumped(logic::Player* p) {
    // p->setJumpHeight(_boost);
    // p->setJumpDuration(1.0);
    // Notify(logic::EVENT::JUMP);
}

int logic::ComplexEnemy::getHP() const {
    return _HP;
}

bool logic::ComplexEnemy::Collided(logic::Player* p) {
	if (p->getHitPoints() > 0) {
		p->setHitPoints(p->getHitPoints()-1);
        _HP--;
	}
    if (_HP) {
        return false;
    }
	return true;
}