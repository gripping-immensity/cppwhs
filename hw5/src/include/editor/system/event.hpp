#pragma once

#include <optional>

#include <editor/action.hpp>

namespace editor {

struct Event {
    virtual std::optional<Action> Process(Window*);

    virtual ~Event();
};


}
