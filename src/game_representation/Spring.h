

#ifndef DOODLE_JUMP_VIEW_SPRING_H
#define DOODLE_JUMP_VIEW_SPRING_H

#include "Bonus.h"
#include "../logic_library/Spring.h"

namespace view {
    class Spring final : public view::Bonus {
    public:
        explicit Spring(std::shared_ptr<logic::Bonus>&);
        ~Spring() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Bonus> _subject;
    };
}
#endif
