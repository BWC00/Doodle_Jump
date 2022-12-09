//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_SCORE_H
#define DOODLE_JUMP_LOGIC_SCORE_H

#include "Observer.h"
#include "Subject.h"
#include "Camera.h"
#include <vector>
#include <memory>

namespace logic {
    class Subject;
    class Platform;
    class Camera;
    class Bonus;
    class Score : public logic::Observer, public logic::Subject {
    public:
	    Score(const std::shared_ptr<logic::Camera>&);
	    ~Score() override = default;
        void Update(logic::EVENT, logic::Subject*) override;
        int getScore() const;
    private:
        std::vector<std::weak_ptr<logic::Platform>> _platforms;
        std::vector<std::weak_ptr<logic::Bonus>> _bonuses;
        std::weak_ptr<logic::Camera> _view;
        int _score;
    };
}

#endif //DOODLE_JUMP_SCORE_H
