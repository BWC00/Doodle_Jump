//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_PLAYER_H
#define DOODLE_JUMP_LOGIC_PLAYER_H

#include "EntityModel.h"
#include "Platform.h"
#include <deque>

namespace logic {

    enum class PLAYER {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    class Player : public logic::EntityModel {
    public:
        Player(double, double);
        ~Player() override = default;
        void setJumpHeight(double);
        void setJumpDuration(double);
        PLAYER getDirection() const;
        void Update(logic::INPUT) override;
        const std::pair<double, double>& getPrevPosition() const;
        void Jumped();
        PLAYER getFacing() const;
        std::weak_ptr<logic::Platform> _platformUnderPlayer;
        void setHitPoints(int k);
        int getHitPoints() const;
        void setLowerBound(double a);
        void setUpperBound(double a);
        void died();
    private:
        PLAYER _direction;
        PLAYER _facing;
        bool _jumped;
        std::pair<double, double> _velocity;
        std::pair<double, double> _prevPosition;
        double _jumpHeight;
        double _jumpTime;
        int _hitPoints;
        bool _dead;
        double _lowerBound;
        double _upperBound;
    };
}

#endif //DOODLE_JUMP_LOGIC_PLAYER_H
