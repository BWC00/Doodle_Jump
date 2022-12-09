//
// Created by razer_blade on 20/11/2021.
//

#include <cmath>
#include "Camera.h"
#include "Player.h"
#include <iostream>

logic::Camera::Camera() : _lost(false) {
//_renderWindow.first = 1200;
 //   _renderWindow.second = 1800;
    reset();
}

bool logic::Camera::getLost() const {
    return _lost;
}

void logic::Camera::reset() {
    _windowBounds.first = 2.0;
    _windowBounds.second = 5.0;
}

double logic::Camera::getLowerBound() const {
    return _windowBounds.first;
}

double logic::Camera::getUpperBound() const {
    return _windowBounds.second;
}

void logic::Camera::shift_view(double amount) {
    _windowBounds.first += amount;
    _windowBounds.second += amount;
}
std::pair<int, int> logic::Camera::project(const std::pair<double, double>& position) {
    return std::make_pair(static_cast<int>(std::round((position.first+1.0)*(600.0/2.0))),
    static_cast<int>(std::round((_windowBounds.second-position.second)*(900.0/3.0))));
}

//std::pair<int, int> logic::Camera::project(double x, double y) const {
//    return std::make_pair(static_cast<int>(std::round((x+1.0)*(((double) _renderWindow.first)/2.0))),
//    static_cast<int>(std::round((_windowBounds.second-y)*(((double) _renderWindow.second)/3.0))));
//}

void logic::Camera::Update(std::shared_ptr<logic::Player> player) {
    double amount = player->getPosition().second - (_windowBounds.first + 3.0/1.6); //1.95
    if (amount > 0) {
        //std::cout << amount << std::endl;
        shift_view(amount);
        Notify(logic::EVENT::MOVE);
    }
}
