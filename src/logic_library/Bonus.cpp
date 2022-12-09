//
// Created by razer_blade on 20/11/2021.
//

#include "Bonus.h"
#include "Player.h"

logic::Bonus::Bonus(double x, double y) : logic::EntityModel(x,y) {}

void logic::Bonus::Update(logic::INPUT) {

}

void logic::Bonus::setUsed(bool k) {
	_used = k;
}

bool logic::Bonus::getUsed() const {
	return _used;
}