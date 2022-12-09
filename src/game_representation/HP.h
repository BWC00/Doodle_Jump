#ifndef DOODLE_JUMP_VIEW_HP_H
#define DOODLE_JUMP_VIEW_HP_H

#include "Bonus.h"
#include "../logic_library/HP.h"

namespace view {
    class HP final : public view::Bonus {
    public:
        explicit HP(std::shared_ptr<logic::Bonus>&);
        ~HP() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Bonus> _subject;
    };
}
#endif