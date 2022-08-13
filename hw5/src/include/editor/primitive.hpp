#pragma once
#include <editor/document.hpp>

namespace editor {

using Point = std::pair<int, int>;
using Rect = std::pair<Point, Point>;

struct Document;
struct Bytestream;

struct Primitive {
public:
    virtual void Draw(Document* document) = 0;
    virtual Rect Box() const = 0;
    virtual bool Intersects(Point p) const = 0;
    virtual Bytestream Serialize() const = 0;

    virtual ~Primitive();
public:
    int depth_index_;
};

}
