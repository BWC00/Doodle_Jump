//
// Created by razer_blade on 20/11/2021.
//

#include "Platform.h"
#include "Player.h"
#include <iostream>

//int logic::Platform::count = 0;

logic::Platform::Platform(double x, double y) : logic::EntityModel(x,y), _hits(0), _bonus(nullptr), _uniquedelta(0), _hasBonus(false) {
    _hitBox.first = 0.37;
    _hitBox.second = 0.10;


//    _count = count; //toegevoegd
//    count++;
}

//logic::Platform::~Platform() {
////    std::cout << "destructor: " << _count << "\n";
//}

std::shared_ptr<logic::Bonus> logic::Platform::getBonus() {
    return _bonus;
}

void logic::Platform::useBonus() {
	_bonus = nullptr;
	_hasBonus = false;
}
bool logic::Platform::hasBonus() const {
	return _hasBonus;
}

int logic::Platform::getUniqueDelta() const {
    return _uniquedelta;
}

void logic::Platform::resetHits() {
    _hits = 0;
}

void logic::Platform::Hit() {
    _hits++;
}

int logic::Platform::getHits() const {
    return _hits;
}