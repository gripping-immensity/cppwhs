#include <iostream>

#include <editor/window.hpp>
#include <editor/system/system_context.hpp>

int main() {
    try {
        editor::SystemContext context;
        editor::Window window(&context);
        auto event_queue = context.GetEventQueue();

        // Main loop
        while (window.IsActive()) {
            // event dispatching
            while(!event_queue->IsEmpty()) {
                auto event = event_queue->PollEvent();
                event->Process();
            }

            window.SwapBuffers();
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
