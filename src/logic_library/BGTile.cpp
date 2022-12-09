//
// Created by razer_blade on 07/12/2021.
//

#include "BGTile.h"

logic::BGTile::BGTile(double x, double y) : logic::EntityModel(x,y) {
    _hitBox.first = 0.05;
    _hitBox.second = 0.05;
}

void logic::BGTile::Update(logic::INPUT input) {
}