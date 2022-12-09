

#ifndef DOODLE_JUMP_VIEW_HORIZONTAL_H
#define DOODLE_JUMP_VIEW_HORIZONTAL_H

#include "Platform.h"
#include "../logic_library/Horizontal.h"

namespace view {
    class Horizontal final : public view::Platform {
    public:
        explicit Horizontal(const std::shared_ptr<logic::Horizontal>&);
        ~Horizontal() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Horizontal> _subject;
    };
}
#endif
