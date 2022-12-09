//
// Created by razer_blade on 18/11/2021.
//

#include "Game.h"
#include "Data.h"
#include "../logic_library/Stopwatch.h"
view::Game::Game(int windowWidth, int windowHeight) : _running(true), _input(logic::INPUT::NONE) {

    //init
    Data::load();
    createWindow(windowWidth, windowHeight);
    createFactory();
    createWorld();

    //run
    run();
}

void view::Game::run() {
    _running = true;
  while(_running) { //zet in juiste volgorde
      HandleInput();
      clearWindow();
      Sleep();
      Update();
      Display();
  }
}

void view::Game::createFactory() {
    _factory = std::make_shared<view::ConcreteFactory>(_window);
}

void view::Game::createWorld() {
    _world = std::make_unique<logic::World>(_factory);
}

void view::Game::Sleep() {
    logic::Stopwatch::sleep();
}

void view::Game::clearWindow() {
    _window->clear(sf::Color::Black);
}

void view::Game::Display() {
    _window->display();
}

void view::Game::HandleInput() {
    sf::Event event{};
    while(_window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _window->close();
            _running = false;
        }
    }
	if (!_running) {
		_input = logic::INPUT::EXIT;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _input = logic::INPUT::RIGHT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _input = logic::INPUT::LEFT;
    } else {
        _input = logic::INPUT::NONE;
    }
}

void view::Game::createWindow(int width, int height) {
    _window = std::make_shared<sf::RenderWindow>();
  _window->create(sf::VideoMode(width, height), "Doodle Jump");
  //_window.setIcon(m_app_icon.getSize().x, m_app_icon.getSize().y, m_app_icon.getPixelsPtr());
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  _window->setPosition(sf::Vector2i(desktop.width / 2 - _window->getSize().x/2, desktop.height/2 - _window->getSize().y/2));
}

void view::Game::Update(){
    _world->update(_input);
}

//void view::Game::reset() {
//
//}