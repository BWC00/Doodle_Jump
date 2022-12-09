

#ifndef DOODLE_JUMP_VIEW_TEMPORARY_H
#define DOODLE_JUMP_VIEW_TEMPORARY_H

#include "Platform.h"
#include "../logic_library/Temporary.h"

namespace view {
    class Temporary final : public view::Platform {
    public:
        //Temporary(logic::Temporary*);
        ~Temporary() override = default;
        explicit Temporary(const std::shared_ptr<logic::Temporary>&);
        void Update(logic::EVENT,logic::Subject*);
    private:
    	std::weak_ptr<logic::Temporary> _subject;
    };
}
#endif