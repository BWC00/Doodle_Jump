//
// Created by razer_blade on 20/11/2021.
//

#include "ConcreteFactory.h"

#include <utility>
#include "Player.h"
#include "Horizontal.h"
#include "Vertical.h"
#include "Static.h"
#include "Temporary.h"
#include "Jetpack.h"
#include "Spring.h"
#include "BGTile.h"
#include "Score.h"
#include "Spike.h"
#include "HP.h"
#include "VerticalTeleport.h"
#include "HorizontalTeleport.h"
#include "SimpleEnemy.h"
#include "ComplexEnemy.h"
#include "../logic_library/Random.h"
#include <iostream>
//#include "../logic_library/Random.h"

view::ConcreteFactory::ConcreteFactory(std::shared_ptr<sf::RenderWindow>  window) : _window(std::move(window)) {
    _view = std::make_shared<logic::Camera>();
    _score = std::make_shared<logic::Score>(_view);
    std::shared_ptr<view::Score> view_score = std::make_shared<view::Score>(_score);
    _score->Attach(logic::EVENT::TICK, view_score);
    view_score->setView(_view);
    view_score->setWindow(_window);
    //std::shared_ptr<view::Score> score_view = std::make_shared<view::Score>(_score);
    //_score->Attach(logic::EVENT::TICK, score_view);
    //score_view->setView(_view);
    //score_view->setWindow(_window);
    _view->Attach(logic::EVENT::MOVE, _score); //score moet geupdatted worden wnr de camera moves
}


std::shared_ptr<logic::Player> view::ConcreteFactory::createPlayer(double x, double y) {
    std::shared_ptr<logic::Player> player_model = std::make_shared<logic::Player>(x,y);
    std::shared_ptr<view::Player> player_view = std::make_shared<view::Player>(player_model);
    player_model->Attach(logic::EVENT::TICK, player_view);
    player_view->setView(_view);
    player_view->setWindow(_window);
    return player_model;
}

std::shared_ptr<logic::Platform> view::ConcreteFactory::createPlatform(double x, double y) {
  //hoe hoger de score hoe kliner de kans om een makkelijke static platform te kiezen -> na deze kans een uniformale verdeling
  //gebruike voor om te kieze tusse andere platforms
    bool easyPlatform = logic::Random::Bernoulli( 1.0/(1+pow(2.71828182,((double) _score->getScore())/5000.0)));
    int randomPlatform = logic::Random::uniformInt(1,4);
    bool generateBonus = logic::Random::Bernoulli(0.1);
    int whichBonus = logic::Random::uniformInt(1,6);
    if (easyPlatform) {
      std::shared_ptr<logic::Static> platform_model = std::make_shared<logic::Static>(x,y);
      std::shared_ptr<view::Static> platform_view = std::make_shared<view::Static>(platform_model);
      if (generateBonus) {
        if (whichBonus == 1) {
          platform_model->_bonus = std::make_shared<logic::Spring>(x,y);
          std::shared_ptr<view::Spring> bonus_view = std::make_shared<view::Spring>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 2) {
          platform_model->_bonus = std::make_shared<logic::Jetpack>(x,y);
          std::shared_ptr<view::Jetpack> bonus_view = std::make_shared<view::Jetpack>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 3) {
          platform_model->_bonus = std::make_shared<logic::Spike>(x,y);
          std::shared_ptr<view::Spike> bonus_view = std::make_shared<view::Spike>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 4) {
          platform_model->_bonus = std::make_shared<logic::HP>(x,y);
          std::shared_ptr<view::HP> bonus_view = std::make_shared<view::HP>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 5) {
          platform_model->_bonus = std::make_shared<logic::SimpleEnemy>(x,y);
          std::shared_ptr<view::SimpleEnemy> bonus_view = std::make_shared<view::SimpleEnemy>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 6) {
          platform_model->_bonus = std::make_shared<logic::ComplexEnemy>(x,y);
          std::shared_ptr<view::ComplexEnemy> bonus_view = std::make_shared<view::ComplexEnemy>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        }
        platform_model->_bonus->Attach(logic::EVENT::JUMP, _score);
        platform_model->_hasBonus = true;
      }
      platform_model->Attach(logic::EVENT::JUMP, _score);
      platform_model->Attach(logic::EVENT::JUMP, platform_view);
      platform_model->Attach(logic::EVENT::TICK, platform_view);
      platform_model->Attach(logic::EVENT::DELETE, _score);
      platform_view->setView(_view);
      platform_view->setWindow(_window);
      return platform_model;
    } else if (randomPlatform == 1) {
      std::shared_ptr<logic::Horizontal> platform_model = std::make_shared<logic::Horizontal>(x,y);
      std::shared_ptr<view::Horizontal> platform_view = std::make_shared<view::Horizontal>(platform_model);
      if (generateBonus) {
        if (whichBonus == 1) {
          platform_model->_bonus = std::make_shared<logic::Spring>(x,y);
          std::shared_ptr<view::Spring> bonus_view = std::make_shared<view::Spring>(platform_model->_bonus);
          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 2) {
          platform_model->_bonus = std::make_shared<logic::Jetpack>(x,y);
          std::shared_ptr<view::Jetpack> bonus_view = std::make_shared<view::Jetpack>(platform_model->_bonus);
          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 3) {
          platform_model->_bonus = std::make_shared<logic::Spike>(x,y);
          std::shared_ptr<view::Spike> bonus_view = std::make_shared<view::Spike>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 4) {
          platform_model->_bonus = std::make_shared<logic::HP>(x,y);
          std::shared_ptr<view::HP> bonus_view = std::make_shared<view::HP>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 5) {
          platform_model->_bonus = std::make_shared<logic::SimpleEnemy>(x,y);
          std::shared_ptr<view::SimpleEnemy> bonus_view = std::make_shared<view::SimpleEnemy>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        } else if (whichBonus == 6) {
          platform_model->_bonus = std::make_shared<logic::ComplexEnemy>(x,y);
          std::shared_ptr<view::ComplexEnemy> bonus_view = std::make_shared<view::ComplexEnemy>(platform_model->_bonus);

          platform_model->_bonus->Attach(logic::EVENT::JUMP, bonus_view);
          platform_model->_bonus->Attach(logic::EVENT::TICK, bonus_view);
          bonus_view->setView(_view);
          bonus_view->setWindow(_window);
        }
        platform_model->_bonus->Attach(logic::EVENT::JUMP, _score);
        platform_model->_hasBonus = true;
      }

      platform_model->Attach(logic::EVENT::JUMP, _score);
      platform_model->Attach(logic::EVENT::JUMP, platform_view);
      platform_model->Attach(logic::EVENT::TICK, platform_view);
      platform_model->Attach(logic::EVENT::DELETE, _score);
      platform_view->setView(_view);
      platform_view->setWindow(_window);
      return platform_model;
    } else if (randomPlatform == 2) {
      std::shared_ptr<logic::Temporary> platform_model = std::make_shared<logic::Temporary>(x,y);
      std::shared_ptr<view::Temporary> platform_view = std::make_shared<view::Temporary>(platform_model);
      platform_model->Attach(logic::EVENT::JUMP, _score);
      platform_model->Attach(logic::EVENT::JUMP, platform_view);
      platform_model->Attach(logic::EVENT::TICK, platform_view);
      platform_model->Attach(logic::EVENT::DELETE, _score);
      platform_view->setView(_view);
      platform_view->setWindow(_window);
      return platform_model;
    } else if (randomPlatform == 3) {
      std::shared_ptr<logic::VerticalTeleport> platform_model = std::make_shared<logic::VerticalTeleport>(x,y);
      std::shared_ptr<view::VerticalTeleport> platform_view = std::make_shared<view::VerticalTeleport>(platform_model);
      platform_model->Attach(logic::EVENT::JUMP, _score);
      platform_model->Attach(logic::EVENT::JUMP, platform_view);
      platform_model->Attach(logic::EVENT::TICK, platform_view);
      platform_model->Attach(logic::EVENT::DELETE, _score);
      platform_view->setView(_view);
      platform_view->setWindow(_window);
      return platform_model;
    } else if (randomPlatform == 4) {
      std::shared_ptr<logic::HorizontalTeleport> platform_model = std::make_shared<logic::HorizontalTeleport>(x,y);
      std::shared_ptr<view::HorizontalTeleport> platform_view = std::make_shared<view::HorizontalTeleport>(platform_model);
      platform_model->Attach(logic::EVENT::JUMP, _score);
      platform_model->Attach(logic::EVENT::JUMP, platform_view);
      platform_model->Attach(logic::EVENT::TICK, platform_view);
      platform_model->Attach(logic::EVENT::DELETE, _score);
      platform_view->setView(_view);
      platform_view->setWindow(_window);
      return platform_model;
    }
    return std::make_shared<logic::Static>(x,y);
}

std::shared_ptr<logic::BGTile> view::ConcreteFactory::createBGTile(double x, double y) {
    std::shared_ptr<logic::BGTile> tile_model =  std::make_shared<logic::BGTile>(x,y);
    std::shared_ptr<view::BGTile> tile_view = std::make_shared<view::BGTile>(tile_model);
    tile_model->Attach(logic::EVENT::TICK, tile_view);
    tile_view->setView(_view);
    tile_view->setWindow(_window);
    return tile_model;
}

//logic::Bonus* view::ConcreteFactory::createBonus(double x, double y) {
//
//}

std::shared_ptr<logic::Camera> view::ConcreteFactory::createCamera() {
    return _view;
}

std::shared_ptr<logic::Score> view::ConcreteFactory::createScore() {
    return _score;
}