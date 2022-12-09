

#ifndef DOODLE_JUMP_VIEW_JETPACK_H
#define DOODLE_JUMP_VIEW_JETPACK_H

#include "Bonus.h"
#include "../logic_library/Jetpack.h"

namespace view {
    class Jetpack final : public view::Bonus {
    public:
        explicit Jetpack(std::shared_ptr<logic::Bonus>&);
        ~Jetpack() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Bonus> _subject;
    };
}
#endif