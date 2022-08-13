#pragma once

#include <editor/action.hpp>

namespace editor {

struct Event {
    virtual Action Process();

    virtual ~Event();
};


}
