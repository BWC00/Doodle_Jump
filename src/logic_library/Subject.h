//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_SUBJECT_H
#define DOODLE_JUMP_LOGIC_SUBJECT_H
//#include "Observer.h"
#include "EVENT.h"
#include <vector>
#include <memory>
#include <map>

namespace logic {
    class Observer;

    class Subject {
    public:
        virtual ~Subject();
	    void Attach(logic::EVENT, std::shared_ptr<logic::Observer>);
        void Notify(logic::EVENT);
    private:
        std::map<logic::EVENT,std::vector<std::shared_ptr<logic::Observer>>> _observers;
    };
}

#endif //DOODLE_JUMP_LOGIC_SUBJECT_H
