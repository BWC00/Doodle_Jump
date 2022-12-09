#ifndef DOODLE_JUMP_VIEW_SIMPLEENEMY_H
#define DOODLE_JUMP_VIEW_SIMPLEENEMY_H

#include "Bonus.h"
#include "../logic_library/SimpleEnemy.h"

namespace view {
    class SimpleEnemy final : public view::Bonus {
    public:
        explicit SimpleEnemy(std::shared_ptr<logic::Bonus>&);
        ~SimpleEnemy() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Bonus> _subject;
    };
}
#endif