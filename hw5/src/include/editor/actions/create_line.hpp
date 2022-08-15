#pragma once

#include <utility>

#include <editor/action.hpp>
#include <editor/primitive.hpp>

namespace editor {

using Point = std::pair<int, int>;

struct CreateLine : Action {
public:
    virtual void Execute() override;
    virtual void Undo() override;
    ~CreateLine() override;
public:
    std::pair<Point, Point> line_segment_;
    Primitive* primitive_ = nullptr;
};

}