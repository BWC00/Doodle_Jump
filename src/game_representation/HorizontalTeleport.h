#ifndef DOODLE_JUMP_VIEW_HORIZONTALTELEPORT_H
#define DOODLE_JUMP_VIEW_HORIZONTALTELEPORT_H

#include "Platform.h"
#include "../logic_library/HorizontalTeleport.h"

namespace view {
    class HorizontalTeleport final : public view::Platform {
    public:
        explicit HorizontalTeleport(const std::shared_ptr<logic::HorizontalTeleport>&);
        ~HorizontalTeleport() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::HorizontalTeleport> _subject;
    };
}
#endif