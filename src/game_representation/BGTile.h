//
// Created by razer_blade on 20/11/2021.
//

#ifndef DOODLE_JUMP_VIEW_BGTILE_H
#define DOODLE_JUMP_VIEW_BGTILE_H

#include "EntityView.h"
#include "../logic_library/BGTile.h"
namespace view {
    class BGTile final : public view::EntityView {
    public:
        explicit BGTile(const std::shared_ptr<logic::BGTile>& BGTile_model);
        ~BGTile() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::BGTile> _subject;
    };
}
#endif //DOODLE_JUMP_VIEW_BGTILE_H
