#include "Horizontal.h"
#include "Data.h"

view::Horizontal::Horizontal(const std::shared_ptr<logic::Horizontal>& Horizontal_model) {
	_subject = Horizontal_model;
	//_subject->Attach(this);
        _sound.setBuffer(Data::jumpSoundBuffer);
	_sprite.setTexture(view::Data::horizontalPlatformTexture);
}

void view::Horizontal::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
  if (e == logic::EVENT::TICK) {
    std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
    _sprite.setPosition(pixelPosition.first, pixelPosition.second);
    _window->draw(_sprite);
  }
}
