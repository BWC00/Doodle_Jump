//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_RANDOM_H
#define DOODLE_JUMP_LOGIC_RANDOM_H

#include <random>

namespace logic {
    class Random {
    public:
        Random(const Random&) = delete;
        static Random& _getInstance();
        static int uniformInt(int a, int b);
        static double uniformReal(double a, double b);
        static int Bernoulli(double p);
        static double Normal(double m, double n);
    private:	
        Random();
        int _uniformInt(int a, int b);
        double _uniformReal(double a, double b);
        int _bernoulli(double p);
        double _normal(double m, double n);
        std::random_device _r;
        std::mt19937 _generator;
    };
}

#endif
