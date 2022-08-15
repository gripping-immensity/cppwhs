#pragma once

#include <memory>

#include <editor/document.hpp>
#include <editor/action.hpp>
#include <editor/system/event.hpp>

namespace editor {

struct SystemContext;

struct Window {
public:
    Window(SystemContext *context);

    void SetCurrentDocument(std::unique_ptr<Document>& document);
    bool IsActive() const;
    void SwapBuffers();
    void AddAction(const Action& action);
    void ShowErrorMessage(const std::string& message);
    void LogInputEvent(const Event& event);

public:
    int width_;
    int height_;

    std::unique_ptr<Document> current_document_;
    // action list for undo/redo features
    std::vector<Action> actions_;
    // overall log
    std::vector<std::string> log_;
};

}
