//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_STOPWATCH_H
#define DOODLE_JUMP_LOGIC_STOPWATCH_H

#include <chrono>

namespace logic {
    class Stopwatch {
    public:
        Stopwatch(const Stopwatch&) = delete;
        static Stopwatch& getInstance();
        static std::chrono::duration<double, std::milli>& getElapsed();
        void timeit();
        static void sleep();
    private:	
        Stopwatch();
        void resetStart();
        void m_sleep();
        std::chrono::steady_clock::time_point start;
        std::chrono::duration<double, std::milli> dt;
    };
}

#endif //DOODLE_JUMP_LOGIC_STOPWATCH_H
