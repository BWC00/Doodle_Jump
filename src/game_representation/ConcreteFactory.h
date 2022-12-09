//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_CONCRETEFACTORY_H
#define DOODLE_JUMP_VIEW_CONCRETEFACTORY_H

#include "../logic_library/AbstractFactory.h"
#include <SFML/Graphics.hpp>

//TODO: nog implementeren: bonus, meerdere soorten platformen met random kans

namespace view {
    class ConcreteFactory : public logic::AbstractFactory {
    public:
        explicit ConcreteFactory(std::shared_ptr<sf::RenderWindow>);
        ~ConcreteFactory() override = default;
        std::shared_ptr<logic::Player> createPlayer(double x, double y) override;
        std::shared_ptr<logic::Platform> createPlatform(double x, double y) override;
        std::shared_ptr<logic::BGTile> createBGTile(double x, double y) override;
        std::shared_ptr<logic::Camera> createCamera() override;
        std::shared_ptr<logic::Score> createScore() override;
        //logic::Bonus* createBonus(double) override;
    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<logic::Camera> _view = nullptr;
        std::shared_ptr<logic::Score> _score = nullptr;
        //std::vector<std::weak_ptr<view::BGTile>> _tiles;
        //std::vector<std::weak_ptr<view::Platform>> _platforms;
    };
}
#endif //DOODLE_JUMP_VIEW_CONCRETEFACTORY_H

