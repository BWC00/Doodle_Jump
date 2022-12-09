#ifndef DOODLE_JUMP_VIEW_SCORE_H
#define DOODLE_JUMP_VIEW_SCORE_H

#include "EntityView.h"
#include "../logic_library/Score.h"
#include <SFML/Audio.hpp>

namespace view {
    class Score final : public view::EntityView {
    public:
        explicit Score(std::shared_ptr<logic::Score>&);
        ~Score() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
    	sf::Text _scoreText;
        std::weak_ptr<logic::Score> _subject;
    };
}
#endif
