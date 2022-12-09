//
// Created by razer_blade on 20/11/2021.
//

#include "Subject.h"
#include "Observer.h"
#include "../game_representation/BGTile.h"

void logic::Subject::Attach(logic::EVENT e, std::shared_ptr<logic::Observer> o) {
    _observers[e].push_back(o);
}

logic::Subject::~Subject() {
    Notify(logic::EVENT::DELETE);
}

//moeten we ook detach implementeren?

void logic::Subject::Notify(logic::EVENT e) {
    for (auto& observer : _observers[e]) {
        observer->Update(e,this);
    }
}
