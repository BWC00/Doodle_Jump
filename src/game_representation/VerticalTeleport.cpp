#include "VerticalTeleport.h"
#include "Data.h"

view::VerticalTeleport::VerticalTeleport(const std::shared_ptr<logic::VerticalTeleport>& VerticalTeleport_model) {
    _subject = VerticalTeleport_model;
    _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::platformTexture);
}

void view::VerticalTeleport::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        _sound.play();
    }
}