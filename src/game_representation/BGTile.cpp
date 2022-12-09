//
// Created by razer_blade on 20/11/2021.
//

#include "BGTile.h"
#include "Data.h"

view::BGTile::BGTile(const std::shared_ptr<logic::BGTile>& BGTile_model) {
	_subject = BGTile_model;
	_sprite.setTexture(view::Data::tile);
}

void view::BGTile::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = _view->project(_subject.lock()->getPosition());
		_sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    }
}