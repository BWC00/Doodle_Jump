#ifndef DOODLE_JUMP_VIEW_VERTICALTELEPORT_H
#define DOODLE_JUMP_VIEW_VERTICALTELEPORT_H

#include "Platform.h"
#include "../logic_library/VerticalTeleport.h"

namespace view {
    class VerticalTeleport final : public view::Platform {
    public:
        explicit VerticalTeleport(const std::shared_ptr<logic::VerticalTeleport>&);
        ~VerticalTeleport() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::VerticalTeleport> _subject;
    };
}
#endif