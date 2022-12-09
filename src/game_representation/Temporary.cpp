#include "Temporary.h"
#include "Data.h"

view::Temporary::Temporary(const std::shared_ptr<logic::Temporary>& Temporary_model) {
    _subject = Temporary_model;
    _sound.setBuffer(view::Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::temporaryPlatformTexture);
}

void view::Temporary::Update(logic::EVENT e, logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        _sound.play();
    }
}