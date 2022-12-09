#ifndef DOODLE_JUMP_LOGIC_HORIZONTALTELEPORT_H
#define DOODLE_JUMP_LOGIC_HORIZONTALTELEPORT_H

#include "Platform.h"

namespace logic {
    class HorizontalTeleport final : public logic::Platform {
    public:
      HorizontalTeleport(double x, double y);
      ~HorizontalTeleport() override = default;
        void Update(logic::INPUT) override;
    };
}

#endif