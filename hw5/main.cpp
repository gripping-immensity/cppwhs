#include <iostream>

#include <fmt/core.h>

#include <editor/window.hpp>
#include <editor/system/system_context.hpp>

int main() {
    try {
        editor::SystemContext context;
        editor::Window window(&context);
        auto event_queue = context.GetEventQueue();

        // main loop
        while (window.IsActive()) {
            // event dispatching
            while(!event_queue->IsEmpty()) {
                auto event = event_queue->PollEvent();
                window.LogInputEvent(event);
                auto action = event.Process(&window);

                // if event didn't trigger any action - go on next
                if (!action) {
                    continue;
                }

                try {
                    action.value().Execute();
                    window.AddAction(action.value());
                }
                // @TODO make exception dedicated to processing actions
                catch (std::exception& e) {
                    window.ShowErrorMessage(fmt::format("Couldn't execute action : {}", e.what()));
                }
            }

            window.SwapBuffers();
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
