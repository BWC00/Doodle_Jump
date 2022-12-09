#include "Vertical.h"
#include "Data.h"


view::Vertical::Vertical(const std::shared_ptr<logic::Vertical>& Vertical_model) {
  _subject = Vertical_model;
  _sound.setBuffer(Data::jumpSoundBuffer);
  _sprite.setTexture(view::Data::verticalTeleportPlatformTexture);

}

void view::Vertical::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
  if (e == logic::EVENT::TICK) {
    std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
    _sprite.setPosition(pixelPosition.first, pixelPosition.second);
    _window->draw(_sprite);
  } else if (e == logic::EVENT::JUMP) {
    _sound.play();
  }
}