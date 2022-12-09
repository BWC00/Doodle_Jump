//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_OBSERVER_H
#define DOODLE_JUMP_LOGIC_OBSERVER_H

//#include "Subject.h"
#include "EVENT.h"

namespace logic {
    class Subject;
    class Observer {
    public:
        virtual ~Observer() = default;
        virtual void Update(logic::EVENT,logic::Subject*) = 0;
    //protected:
    //    Observer();
    };
}

#endif //DOODLE_JUMP_LOGIC_OBSERVER_H
