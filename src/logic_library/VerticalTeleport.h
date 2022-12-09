#ifndef DOODLE_JUMP_LOGIC_VERTICALTELEPORT_H
#define DOODLE_JUMP_LOGIC_VERTICALTELEPORT_H

#include "Platform.h"

namespace logic {
    class VerticalTeleport final : public logic::Platform {
    public:
      VerticalTeleport(double x, double y);
      ~VerticalTeleport() override = default;
        void Update(logic::INPUT) override;
    };
}

#endif