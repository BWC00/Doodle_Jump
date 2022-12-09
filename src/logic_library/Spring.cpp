#include "Spring.h"
#include "Player.h"

logic::Spring::Spring(double x, double y) : logic::Bonus(x,y) {
    _boost = 4;
    _hitBox.first = 0.2596491;
    _hitBox.second = 0.141666;
    _position.first = x+0.185-(_hitBox.first/2.0);
    _position.second = y+0.07;
}

void logic::Spring::Jumped(logic::Player* p) {
    p->setJumpHeight(_boost);
    p->setJumpDuration(1.0);
    Notify(logic::EVENT::JUMP);
}

bool logic::Spring::Collided(logic::Player* p) {
	return false;
}