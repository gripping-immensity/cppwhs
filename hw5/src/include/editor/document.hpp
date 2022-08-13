#pragma once

#include <vector>

#include <editor/window.hpp>
#include <editor/primitive.hpp>

namespace editor {

struct Window;
struct Bytestream;

struct Document {
    Document();
    Document(const std::string& filepath);

    void SaveToFile(const std::string& filepath) const;
    Primitive* RayCast(Point p) const;
    Bytestream Serialize();

public:
    Window* window_;
    std::vector<std::unique_ptr<Primitive>> primitives_;
};

}
