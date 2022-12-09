#ifndef DOODLE_JUMP_VIEW_SPIKE_H
#define DOODLE_JUMP_VIEW_SPIKE_H

#include "Bonus.h"
#include "../logic_library/Spike.h"

namespace view {
    class Spike final : public view::Bonus {
    public:
        explicit Spike(std::shared_ptr<logic::Bonus>&);
        ~Spike() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
        std::weak_ptr<logic::Bonus> _subject;
    };
}
#endif