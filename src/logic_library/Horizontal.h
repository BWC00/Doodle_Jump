

#ifndef DOODLE_JUMP_LOGIC_HORIZONTAL_H
#define DOODLE_JUMP_LOGIC_HORIZONTAL_H

#include "Platform.h"

namespace logic {

    enum class HORIZONTAL {
      RIGHT,
      LEFT
    };

    class Horizontal : public logic::Platform {
    public:
	    Horizontal(double x, double y);
	    ~Horizontal() override = default;
        void Update(logic::INPUT) override;
      private:
        HORIZONTAL _direction;
    };
}

#endif
