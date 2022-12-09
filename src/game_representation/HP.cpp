#include "HP.h"
#include "Data.h"
view::HP::HP(std::shared_ptr<logic::Bonus>& HP_model) {
	_subject = HP_model;
	// _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::bonusHPTexture);
}

void view::HP::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        // _sound.play();
    }
}