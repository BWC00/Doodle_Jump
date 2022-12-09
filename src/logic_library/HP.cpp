#include "HP.h"
#include "Player.h"

logic::HP::HP(double x, double y) : logic::Bonus(x,y) {
    // _boost = 4;
    _hitBox.first = 0.1298245;
    _hitBox.second = 0.13;
    _position.first = x+0.185-(_hitBox.first/2.0);
    _position.second = y+_hitBox.second;
}

void logic::HP::Jumped(logic::Player* p) {
    // p->setJumpHeight(_boost);
    // p->setJumpDuration(1.0);
    // Notify(logic::EVENT::JUMP);
}

bool logic::HP::Collided(logic::Player* p) {
	p->setHitPoints(p->getHitPoints()+1);
	return true;
}