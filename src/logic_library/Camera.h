//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_CAMERA_H
#define DOODLE_JUMP_LOGIC_CAMERA_H

#include "Subject.h"
#include <utility>

namespace logic {
    class Player;
    class Camera : public logic::Subject {
    public:
	    Camera();
        ~Camera() override = default;
        //static std::pair<int, int> project(double x, double y);
        std::pair<int, int> project(const std::pair<double, double>& position);//, int windowWidth, int windowHeight);
        void shift_view(double amount);
        double getUpperBound() const;
        double getLowerBound() const;
        void Update(std::shared_ptr<logic::Player> player);
        bool getLost() const;
        void reset();
    private:
        std::pair<double, double> _windowBounds;
        bool _lost;
    };
}

#endif //DOODLE_JUMP_LOGIC_CAMERA_H
