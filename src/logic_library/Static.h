

#ifndef DOODLE_JUMP_LOGIC_STATIC_H
#define DOODLE_JUMP_LOGIC_STATIC_H

#include "Platform.h"

namespace logic {
    class Static final : public logic::Platform {
    public:
	    Static(double x, double y);
	    ~Static() override = default;
        void Update(logic::INPUT) override;
    };
}

#endif