#include "Static.h"
#include "Data.h"

view::Static::Static(const std::shared_ptr<logic::Static>& Static_model) {
    _subject = Static_model;
    _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::platformTexture);
}

void view::Static::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    } else if (e == logic::EVENT::JUMP) {
        _sound.play();
    }
}