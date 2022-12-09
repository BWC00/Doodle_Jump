#ifndef DOODLE_JUMP_VIEW_COMPLEXENEMY_H
#define DOODLE_JUMP_VIEW_COMPLEXENEMY_H

#include "Bonus.h"
#include "../logic_library/ComplexEnemy.h"

namespace view {
    class ComplexEnemy final : public view::Bonus {
    public:
        explicit ComplexEnemy(std::shared_ptr<logic::Bonus>&);
        ~ComplexEnemy() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
    	sf::Text _HPText;
        std::weak_ptr<logic::Bonus> _subject;
    };
}
#endif