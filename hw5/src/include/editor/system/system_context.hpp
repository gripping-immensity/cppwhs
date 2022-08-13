#pragma once

#include <memory>
#include <editor/system/event_queue.hpp>

namespace editor {

struct SystemContext {
    SystemContext();

    EventQueue* GetEventQueue() const;

public:
    std::unique_ptr<EventQueue> event_queue_;
};


}

