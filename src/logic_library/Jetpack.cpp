#include "Jetpack.h"
#include "Player.h"

logic::Jetpack::Jetpack(double x, double y) : logic::Bonus(x,y) {
    _boost = 8;
    _hitBox.first = 0.185;
    _hitBox.second = 0.0816666666;
    _position.first = x+0.185-(_hitBox.first/2.0);
    _position.second = y+_hitBox.second;
}

void logic::Jetpack::Jumped(logic::Player* p) {
    p->setJumpHeight(_boost);
    p->setJumpDuration(1.5);
    Notify(logic::EVENT::JUMP);
}

bool logic::Jetpack::Collided(logic::Player* p) {
	return false;
}