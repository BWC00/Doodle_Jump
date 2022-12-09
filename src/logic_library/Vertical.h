

#ifndef DOODLE_JUMP_LOGIC_VERTICAL_H
#define DOODLE_JUMP_LOGIC_VERTICAL_H

#include "Platform.h"

namespace logic {

    enum class VERTICAL {
      UP,
      DOWN,
    };
    class Vertical final : public logic::Platform {
    public:
	    Vertical(double x, double y);
	    ~Vertical() override = default;
        void Update(logic::INPUT) override;
    private:
      VERTICAL _direction;
      float _min;
    };
}

#endif