#include "SimpleEnemy.h"
#include "Bonus.h"
#include "Data.h"
view::SimpleEnemy::SimpleEnemy(std::shared_ptr<logic::Bonus>& SimpleEnemy_model) {
	_subject = SimpleEnemy_model;
	// _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::bonusSimpleEnemyTexture);
}

void view::SimpleEnemy::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        // _sound.play();
    }
}