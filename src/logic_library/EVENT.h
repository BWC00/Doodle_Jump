//
// Created by razer_blade on 09/12/2021.
//

#ifndef DOODLE_JUMP_EVENT_H
#define DOODLE_JUMP_EVENT_H

namespace logic {
    //int (*minus) (int , int) = [](int x, int y) -> int {return x+y;};
    enum class EVENT {
        JUMP,
        MOVE,
        DELETE,
        TICK,
        HIT
    };
}
#endif //DOODLE_JUMP_EVENT_H
