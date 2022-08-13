#pragma once
#include <editor/system/event.hpp>

namespace editor {

struct EventQueue {
    EventQueue();

    bool IsEmpty() const;
    Event* PollEvent();
};


}
