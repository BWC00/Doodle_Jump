#include "Spring.h"
#include "Bonus.h"
#include "Data.h"
view::Spring::Spring(std::shared_ptr<logic::Bonus>& Spring_model) {
	_subject = Spring_model;
	_sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::bonusSpringTexture);
}

void view::Spring::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        _sound.play();
    }
}