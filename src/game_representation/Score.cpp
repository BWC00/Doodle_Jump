#include "Data.h"
#include "Score.h"
#include "EntityView.h"
view::Score::Score(std::shared_ptr<logic::Score>& Score_model) {
	_subject = Score_model;
	_scoreText.setFont(view::Data::font);
    _scoreText.setCharacterSize(50);
    _scoreText.setFillColor(sf::Color::Black);
    _scoreText.setPosition(10, 20);
}

void view::Score::Update(logic::EVENT e,logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        _scoreText.setString("Score: " + std::to_string(_subject.lock()->getScore()));
        _window->draw(_scoreText);
    }
}