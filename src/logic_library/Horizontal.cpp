#include "Horizontal.h"
#include "Random.h"

logic::Horizontal::Horizontal(double x, double y) : logic::Platform(x,y) {
  int randomDirection = logic::Random::uniformInt(0,1);
  _direction = (randomDirection ? logic::HORIZONTAL::RIGHT : logic::HORIZONTAL::LEFT);
}

void logic::Horizontal::Update(logic::INPUT input) {

  if (_position.first + 0.37 >= 1 && _direction == logic::HORIZONTAL::RIGHT) {
    _direction = logic::HORIZONTAL::LEFT;
  } else if (_position.first <= -1 && _direction == logic::HORIZONTAL::LEFT) {
    _direction = logic::HORIZONTAL::RIGHT;
  }

  if (_direction == logic::HORIZONTAL::RIGHT) {
    _position.first += 0.01;
    if (_hasBonus) {
      _bonus->setPosition(_bonus->getPosition().first+0.01, _bonus->getPosition().second);
    }
  } else {
    _position.first -= 0.01;
    if (_hasBonus) {
      _bonus->setPosition(_bonus->getPosition().first-0.01, _bonus->getPosition().second);
    }
  }
}