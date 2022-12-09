

#ifndef DOODLE_JUMP_LOGIC_TEMPORARY_H
#define DOODLE_JUMP_LOGIC_TEMPORARY_H

#include "Platform.h"

namespace logic {
    class Temporary final : public logic::Platform {
    public:
	    Temporary(double x, double y);
	    ~Temporary() override = default;
        void Update(logic::INPUT) override;
    };
}

#endif