//
// Created by razer_blade on 20/11/2021.
//

#include "Random.h"

logic::Random::Random() : _generator(_r()) {

}
logic::Random& logic::Random::_getInstance() {
    static logic::Random instance;
    return instance;
}

int logic::Random::uniformInt(int a, int b) {
    return _getInstance()._uniformInt(a,b);
}

double logic::Random::uniformReal(double a, double b) {
    return _getInstance()._uniformReal(a,b);
}

int logic::Random::Bernoulli(double p) {
    return _getInstance()._bernoulli(p);
}

double logic::Random::Normal(double m, double n) {
    return _getInstance()._normal(m,n);
}

int logic::Random::_uniformInt(int a, int b) {
    std::uniform_int_distribution<int> d(a, b);
    return d(_generator);
}

double logic::Random::_uniformReal(double a, double b) {
    std::uniform_real_distribution<double> d(a, b);
    return d(_generator);
}

int logic::Random::_bernoulli(double p) {
    std::bernoulli_distribution d(p);
    return d(_generator);
}

double logic::Random::_normal(double m, double n) {
    std::normal_distribution<double> d(m,n);
    return d(_generator);
}
