//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_BONUS_H
#define DOODLE_JUMP_VIEW_BONUS_H

#include "EntityView.h"
#include <SFML/Audio.hpp>

namespace view {
    class Bonus : public view::EntityView {
    public:
        ~Bonus() override = default;
    protected:
        sf::Sound _sound;
    };
}

#endif //DOODLE_JUMP_VIEW_BONUS_H
