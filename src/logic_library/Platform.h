//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_PLATFORM_H
#define DOODLE_JUMP_LOGIC_PLATFORM_H

#include "EntityModel.h"

#include "Bonus.h"

namespace logic {
    class Player;
    class Bonus;
    class Platform : public logic::EntityModel {
    public:
	    Platform(double x, double y);
	    ~Platform() override = default;
    	std::shared_ptr<logic::Bonus> getBonus();
        int getHits() const;
        void resetHits();
        int getUniqueDelta() const;
        void Hit();
        bool hasBonus() const;
        void useBonus();

        std::shared_ptr<logic::Bonus> _bonus; //verplaats naar proteected
        bool _hasBonus;

//        int _count; //toegevoegd
    protected:
//        static int count; //toegevoegd debiel
        int _hits;
        int _uniquedelta;
    };
}

#endif //DOODLE_JUMP_LOGIC_PLATFORM_H
