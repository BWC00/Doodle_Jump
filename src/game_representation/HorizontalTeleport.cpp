#include "HorizontalTeleport.h"
#include "Data.h"

view::HorizontalTeleport::HorizontalTeleport(const std::shared_ptr<logic::HorizontalTeleport>& HorizontalTeleport_model) {
    _subject = HorizontalTeleport_model;
    _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::horizontalTeleportPlatformTexture);
}

void view::HorizontalTeleport::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        _sound.play();
    }
}