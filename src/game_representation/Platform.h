//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_PLATFORM_H
#define DOODLE_JUMP_VIEW_PLATFORM_H

#include "EntityView.h"
#include <SFML/Audio.hpp>

namespace view {
    class Platform : public view::EntityView {
    public:
        ~Platform() override = default;
    protected:
        sf::Sound _sound;
    };
}

#endif //DOODLE_JUMP_VIEW_PLATFORM_H
