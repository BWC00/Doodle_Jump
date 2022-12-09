//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_ENTITYVIEW_H
#define DOODLE_JUMP_VIEW_ENTITYVIEW_H

#include "../logic_library/Observer.h"
#include "../logic_library/Camera.h"
#include <SFML/Graphics.hpp>


namespace view {
    class EntityView : public logic::Observer {
    public:
        ~EntityView() override = default;
        void setView(std::shared_ptr<logic::Camera> p);
        void setWindow(std::shared_ptr<sf::RenderWindow> w);
    protected:
        sf::Sprite _sprite;
        std::shared_ptr<logic::Camera> _view;
        std::shared_ptr<sf::RenderWindow> _window;
    };
}

#endif //DOODLE_JUMP_VIEW_ENTITYVIEW_H
