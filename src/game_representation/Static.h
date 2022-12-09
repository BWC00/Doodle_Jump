

#ifndef DOODLE_JUMP_VIEW_STATIC_H
#define DOODLE_JUMP_VIEW_STATIC_H

#include "Platform.h"
#include "../logic_library/Static.h"

namespace view {
    class Static final : public view::Platform {
    public:
        explicit Static(const std::shared_ptr<logic::Static>&);
        ~Static() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Static> _subject;
    };
}
#endif
