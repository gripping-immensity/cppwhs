#pragma once

#include <utility>

#include <editor/action.hpp>
#include <editor/primitive.hpp>

namespace editor {

struct DeleteLine : Action {
public:
    virtual void Execute() override;
    virtual void Undo() override;
    ~DeleteLine() override;
public:
    std::pair<Point, Point> line_segment_;
    Primitive* primitive_ = nullptr;
};

}