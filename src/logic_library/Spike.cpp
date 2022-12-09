#include "Spike.h"
#include "Player.h"

logic::Spike::Spike(double x, double y) : logic::Bonus(x,y) {
    // _boost = 4;
    _hitBox.first = 0.1622807;
    _hitBox.second = 0.086666;
    _position.first = x+0.185-(_hitBox.first/2.0);
    _position.second = y+_hitBox.second;
}

void logic::Spike::Jumped(logic::Player* p) {
    // p->setJumpHeight(_boost);
    // p->setJumpDuration(1.0);
    // Notify(logic::EVENT::JUMP);
}

bool logic::Spike::Collided(logic::Player* p) {
	if (p->getHitPoints() > 0) {
		p->setHitPoints(p->getHitPoints()-1);
	}
	return true;
}