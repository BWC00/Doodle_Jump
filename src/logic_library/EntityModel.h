//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_ENTITYMODEL_H
#define DOODLE_JUMP_LOGIC_ENTITYMODEL_H

#include "Subject.h"
#include "INPUT.h"
#include <utility>

namespace logic {
    class EntityModel : public logic::Subject {
    public:
        EntityModel(double x, double y);
        ~EntityModel() override = default;
	    const std::pair<double, double>& getPosition();
        const std::pair<double, double>& getHitbox();
        void setPosition(const std::pair<double, double>& position);
	    void setPosition(double x, double y);
		virtual void Update(logic::INPUT)=0;
    protected:
	    std::pair<double, double> _position;
        std::pair<double, double> _hitBox;
    };
}

#endif //DOODLE_JUMP_LOGIC_ENTITYMODEL_H
