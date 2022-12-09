#include "ComplexEnemy.h"
#include "Bonus.h"
#include "Data.h"
view::ComplexEnemy::ComplexEnemy(std::shared_ptr<logic::Bonus>& ComplexEnemy_model) {
	_subject = ComplexEnemy_model;
	// _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::bonusComplexEnemyTexture);

    _HPText.setFont(view::Data::font);
    _HPText.setCharacterSize(30);
    _HPText.setFillColor(sf::Color::Red);
}

void view::ComplexEnemy::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
        auto ff = dynamic_cast<logic::ComplexEnemy*>(_subject.lock().get());
        _HPText.setString(std::to_string(ff->getHP()) + " HP");
        _HPText.setPosition(10+pixelPosition.first, 20+pixelPosition.second);
        _window->draw(_HPText);
    } else if (e == logic::EVENT::JUMP) {
        // _sound.play();
    }
}