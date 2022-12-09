

#ifndef DOODLE_JUMP_VIEW_VERTICAL_H
#define DOODLE_JUMP_VIEW_VERTICAL_H

#include "Platform.h"
#include "../logic_library/Vertical.h"
namespace view {
    class Vertical final : public view::Platform {
    public:
        explicit Vertical(const std::shared_ptr<logic::Vertical>&);
        ~Vertical() override = default;
        void Update(logic::EVENT,logic::Subject*) override;
    private:
      std::weak_ptr<logic::Vertical> _subject;
    };
}
#endif
