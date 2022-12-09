//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_BONUS_H
#define DOODLE_JUMP_LOGIC_BONUS_H

#include "EntityModel.h"

namespace logic {
    class Player;
    class Bonus : public logic::EntityModel {
    public:
	    Bonus(double x, double y);
	    ~Bonus() override = default;
        void Update(logic::INPUT) override;
        virtual bool Collided(logic::Player*)=0;
        virtual void Jumped(logic::Player*)=0;
        void setUsed(bool);
        bool getUsed() const;
    private:
    	bool _used;
    };
}

#endif //DOODLE_JUMP_LOGIC_BONUS_H
