#include "SimpleEnemy.h"
#include "Player.h"

logic::SimpleEnemy::SimpleEnemy(double x, double y) : logic::Bonus(x,y) {
    // _boost = 4;
    _hitBox.first = 0.1298245;
    _hitBox.second = 0.13;
    _position.first = x+0.185-(_hitBox.first/2.0);
    _position.second = y+_hitBox.second;
}

void logic::SimpleEnemy::Jumped(logic::Player* p) {
    
}

bool logic::SimpleEnemy::Collided(logic::Player* p) {
	if (p->getHitPoints() > 0) {
		p->setHitPoints(p->getHitPoints()-1);
	}
	return true;
}