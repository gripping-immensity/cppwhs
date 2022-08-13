#pragma once

#include <editor/primitive.hpp>

namespace editor {

struct Line : Primitive {
    virtual void Draw(Document* document) override;
    virtual Rect Box() const override;
    virtual bool Intersects(Point p) const override;

    ~Line() override;
};

}
