//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_PLAYER_H
#define DOODLE_JUMP_VIEW_PLAYER_H

#include "EntityView.h"
#include "../logic_library/Player.h"
namespace view {
    class Player final : public view::EntityView {
    public:
        explicit Player(const std::shared_ptr<logic::Player>&);
        ~Player() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Player> _subject;
        sf::Text _HPText;
    };
}

#endif //DOODLE_JUMP_VIEW_PLAYER_H
