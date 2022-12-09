//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_LOGIC_WORLD_H
#define DOODLE_JUMP_LOGIC_WORLD_H

//#include "Camera.h"
//#include "Player.h"
#include "AbstractFactory.h"
//#include "Score.h"
//#include "Platform.h"
#include "INPUT.h"
#include <vector>
#include <deque>

namespace logic {
    class World {
    public:
	    explicit World(const std::shared_ptr<logic::AbstractFactory>&);
        void update(INPUT);
    private:
		std::shared_ptr<logic::Camera> _view;
		std::shared_ptr<logic::Player> _player;
		std::shared_ptr<logic::AbstractFactory> _factory;
		std::shared_ptr<logic::Score> _score;
        std::deque<std::vector<std::shared_ptr<logic::BGTile>> > _tiles;
        std::deque<std::shared_ptr<logic::Platform>> _platforms;
        int _platformUnderPlayer;
        std::weak_ptr<logic::Platform> _prevJumpedPlatform;
        void _initPlatforms();
        void _initBGTiles();
        void getPlatformUnderPlayer();
        bool collisionWithPlayer(const std::shared_ptr<logic::EntityModel>& object) const;
        void reset();
        void tick();
        void exit();
    };
}

#endif //DOODLE_JUMP_LOGIC_WORLD_H


//bepaal met de score de interval waarbinnen platforms gegenereerd kunnen worden
//in het begin zijn die intervallen kort, in elke int4erval wordt er random een platform gegenereerd.
