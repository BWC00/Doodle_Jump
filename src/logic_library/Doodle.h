//
// Created by razer_blade on 16/12/2021.
//

#ifndef DOODLE_JUMP_DOODLE_H
#define DOODLE_JUMP_DOODLE_H

#include "Player.h"

namespace logic {
    class Doodle final : public logic::Player {
    public:
        Doodle(double, double);
        ~Doodle() override = default;
    };
}



#endif //DOODLE_JUMP_DOODLE_H
