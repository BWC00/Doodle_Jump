//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_ABSTRACTFACTORY_H
#define DOODLE_JUMP_LOGIC_ABSTRACTFACTORY_H

#include "Player.h"
#include "Platform.h"
#include "BGTile.h"
//#include "Bonus.h"
#include "Score.h"

namespace logic {
    class AbstractFactory {
    public:
	    virtual std::shared_ptr<logic::Player> createPlayer(double, double) = 0;
	    virtual std::shared_ptr<logic::Platform> createPlatform(double, double) = 0;
	    virtual std::shared_ptr<logic::BGTile> createBGTile(double, double) = 0;
        virtual ~AbstractFactory() = default;
	    //virtual logic::Bonus* createBonus() = 0;
        virtual std::shared_ptr<logic::Camera> createCamera() = 0;
        virtual std::shared_ptr<logic::Score> createScore() = 0;
    };
}

#endif //DOODLE_JUMP_LOGIC_ABSTRACTFACTORY_H
