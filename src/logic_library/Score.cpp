//
// Created by razer_blade on 20/11/2021.
//

#include "Score.h"
#include "Platform.h"
#include "Camera.h"
#include <cmath>

logic::Score::Score(const std::shared_ptr<logic::Camera>& view) : _score(0) {
    _view = view;
}

int logic::Score::getScore() const {
    return _score;
}

void logic::Score::Update(logic::EVENT e, logic::Subject* changedSubject) {
    if (changedSubject == _view.lock().get()) {
        //if (!_view.lock()->getLost()) {
        if (e == logic::EVENT::MOVE) {
            _score = static_cast<int>(std::round(5*(((double)(_view.lock()->getLowerBound()-2))/0.10))); //15
        }
        //}
    } else {
        for (auto it = _platforms.begin(); it!=_platforms.end(); it++) {
            if (changedSubject == it->lock().get()) {
                if (e == logic::EVENT::DELETE) {
                    _platforms.erase(it);
                } else if ((e == logic::EVENT::JUMP) && (it->lock()->getHits() > 1)) {
                    _score = std::max(0,_score+it->lock()->getUniqueDelta());
                }
                break;
            }
        }
/*        for (auto it = _bonuses.begin(); it!=_bonuses.end(); it++) {
            if (changedSubject == it->lock().get()) {
//add bonus
            }
        }*/
    }
}