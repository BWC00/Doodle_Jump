//
// Created by razer_blade on 20/11/2021.
//

#include "Player.h"
#include <utility>
#include "Data.h"
#include <iostream>


view::Player::Player(const std::shared_ptr<logic::Player>& Player_model) {
	_subject = Player_model;
    _sprite.setTexture(view::Data::rightTexture);
    _HPText.setFont(view::Data::font);
    _HPText.setCharacterSize(50);
    _HPText.setFillColor(sf::Color::Green);
    _HPText.setPosition(10, 80);
}

void view::Player::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
        //std::cout << "x: " << pixelPosition.first << ", y: " << pixelPosition.second << std::endl;
        //std::cout << "x: " << _subject.lock()->getPosition().first << ", y: " << _subject.lock()->getPosition().second << std::endl;
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
/*        if (_subject.lock()->getFacing() == logic::PLAYER::RIGHT) { als player left kijkt -> de collisiondetection faalt
            _sprite.setTexture(view::Data::rightTexture);
        } else {
            _sprite.setTexture(view::Data::leftTexture);
        }*/
        _window->draw(_sprite);

        _HPText.setString("HP: " + std::to_string(_subject.lock()->getHitPoints()));
        _window->draw(_HPText);
    }
}
