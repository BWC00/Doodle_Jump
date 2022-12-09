//
// Created by razer_blade on 18/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_GAME_H
#define DOODLE_JUMP_VIEW_GAME_H

#include "../logic_library/World.h"
#include "ConcreteFactory.h"
#include <SFML/Graphics.hpp>
#include "../logic_library/INPUT.h"
namespace view {
        class Game{
    public:
        explicit Game(int windowWidth=600, int windowHeight=900); // 2/3
        ~Game()=default;
    private:
        void HandleInput();
//        void reset();
        void run();
        void Update();
        void Display();
        void clearWindow();
        static void Sleep();
        void createFactory();
        void createWorld();
        void createWindow(int width, int height);
        bool _running;
        logic::INPUT _input;
        std::shared_ptr<sf::RenderWindow> _window;
        std::unique_ptr<logic::World> _world;
        std::shared_ptr<view::ConcreteFactory> _factory;
//        sf::Event _event;
//        sf::Image _icon;
    };
}

#endif //DOODLE_JUMP_VIEW_GAME_H
