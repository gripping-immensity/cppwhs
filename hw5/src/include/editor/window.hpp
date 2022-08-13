#pragma once

#include <memory>

#include <editor/document.hpp>

namespace editor {

struct SystemContext;

struct Window {
public:
    Window(SystemContext *context);

    void SetCurrentDocument(std::unique_ptr<Document>& document);
    bool IsActive() const;
    void SwapBuffers();

public:
    int width_;
    int height_;

    std::unique_ptr<Document> current_document_;
};

}
