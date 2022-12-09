//
// Created by razer_blade on 07/12/2021.
//

#ifndef DOODLE_JUMP_LOGIC_BGTILE_H
#define DOODLE_JUMP_LOGIC_BGTILE_H

#include "EntityModel.h"

namespace logic {
    class BGTile : public logic::EntityModel {
    public:
	    BGTile(double x, double y);
	    ~BGTile() override = default;
        void Update(logic::INPUT) override;
    private:
    };
}

#endif //DOODLE_JUMP_LOGIC_BGTILE_H
