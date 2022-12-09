#include "Spike.h"
#include "Bonus.h"
#include "Data.h"
view::Spike::Spike(std::shared_ptr<logic::Bonus>& Spike_model) {
	_subject = Spike_model;
	// _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::bonusSpikeTexture);
}

void view::Spike::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        // _sound.play();
    }
}