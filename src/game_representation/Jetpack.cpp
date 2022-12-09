#include "Jetpack.h"
#include "Data.h"

view::Jetpack::Jetpack(std::shared_ptr<logic::Bonus>& Jetpack_model) {
	_subject = Jetpack_model;
	_sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::bonusJetpackTexture);
}

void view::Jetpack::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        _sound.play();
    }
}