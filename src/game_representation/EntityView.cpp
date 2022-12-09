//
// Created by razer_blade on 20/11/2021.
//

#include "EntityView.h"

void view::EntityView::setView(std::shared_ptr<logic::Camera> p) {
    _view = p;
}

void view::EntityView::setWindow(std::shared_ptr<sf::RenderWindow> w) {
    _window = w;
}