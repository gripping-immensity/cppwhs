#pragma once

namespace editor {

struct Action {
public:
    virtual void Execute();
    virtual void Undo();
    virtual ~Action();
public:
    // it is supposed to be bound for specific window
    Window* window;
};

}
