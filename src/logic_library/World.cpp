//
// Created by razer_blade on 20/11/2021.
//

#include "World.h"
#include "Random.h"
#include <algorithm>
#include <iostream>
#include "Temporary.h"
//#include "INPUT.h"

//CONSTANTS:
//
//RenderWindow = (1200x1800)
//
//CameraView = (2x3)
//          start_lower_bound: 2
//          start_upper_bound: 5
//
//BGTile:
//  - entity_view:
//                  width:  30px
//                  height: 30px
//  - entity_model:
//                  width:  0.05
//                  height: 0.05
//
//Player:
//  - entity_view:
//                  width:
//                  height:
//  - entity_model:
//                  width: 0.35
//                  height: 0.35
//
//Platform:
//  - entity_view:
//                  width:
//                  height:
//  - entity_model:
//                  width: 0.37
//                  height: 0.10
//0.25*width = distance from origin doodle (left cornor) to left most foot
//0.5*width = length of foot
//min height between 2 platforms = 0.05
//max height between 2 platforms = 
//Bonus: (kan varieren)
//hoogte view: 3
//breedte view: 2
//maak de platforms verder uit elkaar terwijl de score stijgt:
//	- maximum height diff between 2 platforms: m (= jump height of doodle, reached when score is >= 20000);
//	- minimum height diff between 2 platforms: 0.10 (2 tiles heights)
//	- height diff between 2 platforms = std::clamp((scoref/20000f)*m, 0.10, m);
//	origin van player links boven
//	entity_model_width = (entity_view_width/window_width)*2 (2 = view_width)
//	entity_model_height = (entity_view_height/window_height)*3 (3 = view_height)
//	player moet random gegenereerd worden tussen -0.75 en 0.75 (origin van player links boven)


//TODO: implementeer de concretefactory voor het aanmaken van de objecten
//TODO: verander alle raw pointers in smart pointers

logic::World::World(const std::shared_ptr<logic::AbstractFactory>& p) : _factory(p) {
    _view = _factory->createCamera();
    _score = _factory->createScore();
    _initBGTiles();
    reset();
}

void logic::World::_initBGTiles() {
    for (int rij = 0; rij < 60; rij++) { //1 extra tile boven en onder de view
        _tiles.push_back(std::vector<std::shared_ptr<logic::BGTile>>());
        for (int kolom = 0; kolom < 40; kolom++) {
			_tiles[rij].push_back(_factory->createBGTile(-1.0+kolom*0.05, 5.0-rij*0.05)); //kolom: int, * 0.05 !!!!
        }
    }
}

void logic::World::_initPlatforms() {
    int initial_platforms = logic::Random::uniformInt(7,15);
    double platform_height = (3.0- ((double) initial_platforms)*0.10)/((double) initial_platforms);
    for (int i = 0; i < initial_platforms; i++) {
        _platforms.push_back(_factory->createPlatform(logic::Random::uniformReal(-1,1-0.37),(0.10+platform_height)
        *i+2.0+0.10+0.10+logic::Random::uniformReal(0,platform_height-0.10)));
    }
}

void logic::World::reset() {
    _view->reset();
    _player = _factory->createPlayer(logic::Random::uniformReal(-0.75,0.60),3.0);
    _initPlatforms();
    _platformUnderPlayer = 0;
    _player->_platformUnderPlayer = _platforms[_platformUnderPlayer];
}

void logic::World::getPlatformUnderPlayer() {
    double DISTANCE_FROM_ORIGIN_TO_LEFTMOST_FOOT = 0.25*_player->getHitbox().first;
    double DISTANCE_FROM_ORIGIN_TO_RIGHTMOST_FOOT = (0.25+0.48)*_player->getHitbox().first;
    _platformUnderPlayer = 0;
    while ((_platformUnderPlayer+1 < _platforms.size()) && (_platforms[_platformUnderPlayer]->getPosition().second < (_player->getPosition().second-_player->getHitbox().second))) {
        _platformUnderPlayer++;
    }
    while ((_platformUnderPlayer > 0) && (_platforms[_platformUnderPlayer]->getPosition().second > (_player->getPosition().second-_player->getHitbox().second)) && ((_player->getPosition().first+DISTANCE_FROM_ORIGIN_TO_RIGHTMOST_FOOT <= _platforms[_platformUnderPlayer]->getPosition().first) || (_player->getPosition().first+DISTANCE_FROM_ORIGIN_TO_LEFTMOST_FOOT >= _platforms[_platformUnderPlayer]->getPosition().first+_platforms[_platformUnderPlayer]->getHitbox().first))) {
        _platformUnderPlayer--;
    }
    _player->_platformUnderPlayer = _platforms[_platformUnderPlayer];
//
//    _platforms[3]->getPosition().second;
//    _platforms[2]->getPosition().second;
//    _platformUnderPlayer->get()->getPosition().second
//    _platforms[1]->getPosition().second
}

//hou rekening met dat de player niet jumpt op de platform stuk waardat de bonus staat

bool logic::World::collisionWithPlayer(const std::shared_ptr<logic::EntityModel>& object) const {
    double DISTANCE_FROM_ORIGIN_TO_LEFTMOST_FOOT = 0.25*_player->getHitbox().first;
    double DISTANCE_FROM_ORIGIN_TO_RIGHTMOST_FOOT = (0.25+0.48)*_player->getHitbox().first;
    if ((_player->getDirection() == logic::PLAYER::DOWN) && (_player->getPrevPosition().second - _player->getHitbox().second >= object->getPosition().second) && (_player->getPosition().second-_player->getHitbox().second <= object->getPosition().second) && (_player->getPosition().first+DISTANCE_FROM_ORIGIN_TO_RIGHTMOST_FOOT > object->getPosition().first) && (_player->getPosition().first+DISTANCE_FROM_ORIGIN_TO_LEFTMOST_FOOT < object->getPosition().first+object->getHitbox().first)) {
        return true;
    }
    return false;
}

void logic::World::update(INPUT input) {
    if (input == logic::INPUT::EXIT) {
        //exit();
        return;
    }
    _player->Update(input);
        for (int i = 0; i < _platforms.size(); i++) {
        _platforms[i]->Update(input);
    }

    for (int i = 0; i < _platforms.size(); i++) {
        if (not(_platforms[i]->hasBonus())) {
            continue;
        }
        if (((_player->getPosition().first+_player->getHitbox().first > _platforms[i]->getBonus()->getPosition().first) && (_player->getPosition().first < _platforms[i]->getBonus()->getPosition().first+_platforms[i]->getBonus()->getHitbox().first)) && ((_player->getPosition().second > _platforms[i]->getBonus()->getPosition().second-_platforms[i]->getBonus()->getHitbox().second) && (_player->getPosition().second-_player->getHitbox().second < _platforms[i]->getBonus()->getPosition().second))) {
            bool hitted = false;
            if (not(_platforms[i]->getBonus()->getUsed())) {
                hitted = _platforms[i]->getBonus()->Collided(_player.get());
                _platforms[i]->getBonus()->setUsed(true);
            }
            if (hitted) {
                _platforms[i]->useBonus();
                break;
            }
        } else {
            _platforms[i]->getBonus()->setUsed(false);
        }
    }

    if (_player->getHitPoints() == 0) {
        _player->died();
    }

    _player->setLowerBound(_view->getLowerBound());
    _player->setUpperBound(_view->getUpperBound());

    getPlatformUnderPlayer();
    _view->Update(_player);
//    std::cout << _score->getScore() << '\n';
    //hou ook rekening met de bonus die boven de platform ligt

    //neem min tusse "afstand dat de doodle aflegt naar beneden in de y richting met 1 frame" en "de afstand tot de dichtsbijzijnde platform"
    if (_platforms.back()->getPosition().second < _view->getUpperBound()) { //afstand tussen platform1 en platform2 (platform1 zit onder platform2) is (platform2.y-PLATFORM_HEIGHT)-platform1.y
        double PLATFORM_HEIGHT = 0.10;
        double MINIMUM_HEIGHT_DIFF_PLATFORMS = 0.10;
        double DOODLE_JUMP_HEIGHT = 1.2;
        double MAXIMUM_HEIGHT_DIFF_PLATFORMS = DOODLE_JUMP_HEIGHT-PLATFORM_HEIGHT-0.10;
        _platforms.push_back(_factory->createPlatform(logic::Random::uniformReal(-1,1-0.37),PLATFORM_HEIGHT+_platforms.back()->getPosition().second+std::max(std::clamp(Random::Normal(std::min((((double) _score->getScore())/20000.0)+0.1,0.9),0.10), MINIMUM_HEIGHT_DIFF_PLATFORMS, MAXIMUM_HEIGHT_DIFF_PLATFORMS),_view->getUpperBound()-_platforms.back()->getPosition().second)));
    }
    if ((_platforms.front()->getPosition().second < _view->getLowerBound()) || (_platforms.front()->getBonus() && _platforms.front()->getBonus()->getPosition().second < _view->getLowerBound())) {
        _platforms.pop_front();
    }

    if (_platforms[_platformUnderPlayer]->getHits() && dynamic_cast<logic::Temporary*>(_platforms[_platformUnderPlayer].get())) {
        _platforms.erase(_platforms.begin()+_platformUnderPlayer);
    }

    //verwijder platforms van beneden en zie ook ofdat er geen bonuses op kunnen voorkomen
    while (_tiles.back()[0]->getPosition().second < _view->getLowerBound()) {
        _tiles.pop_back();
    }
    while (_tiles.front()[0]->getPosition().second < _view->getUpperBound()) {
        double y_tile = _tiles.front()[0]->getPosition().second;
        double height_tile = _tiles.front()[0]->getHitbox().second;
        _tiles.push_front(std::vector<std::shared_ptr<logic::BGTile>>());
        for (int kolom = 0; kolom < 40; kolom++) {
			_tiles[0].push_back(_factory->createBGTile(-1.0+kolom*0.05, y_tile+height_tile));
        }
    }
    //check collisions
//    if (_platforms[_platformUnderPlayer]->getBonus() && collisionWithPlayer(_platforms[_platformUnderPlayer]->getBonus())) {
//        _platforms[_platformUnderPlayer]->getBonus()->Jumped(_player);
//    } else if (collisionWithPlayer(_platforms[_platformUnderPlayer])) {
//        if ((_prevJumpedPlatform.lock()) && (_prevJumpedPlatform.lock() != _platforms[_platformUnderPlayer])) {
//            _prevJumpedPlatform.lock()->resetHits();
//        }
//        _prevJumpedPlatform = _platforms[_platformUnderPlayer];
//        _platforms[_platformUnderPlayer]->Jumped(_player);
//    }
    tick();
}

void logic::World::tick() {
    for (int i = 0; i < _tiles.size(); i++) {
        for (int k = 0; k < _tiles[0].size(); k++) {
            _tiles[i][k]->Notify(logic::EVENT::TICK);
        }
    }
    for (int i = 0; i < _platforms.size(); i++) {
        _platforms[i]->Notify(logic::EVENT::TICK);
        if (_platforms[i]->hasBonus()) {
            _platforms[i]->getBonus()->Notify(logic::EVENT::TICK);
        }
    }
    _player->Notify(logic::EVENT::TICK);
    _score->Notify(logic::EVENT::TICK);
}
void logic::World::exit() {

}
