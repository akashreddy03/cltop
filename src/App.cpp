#include <chrono>
#include <cltop/App.h>
#include <ncurses.h>

App::App() {}

App::~App() {}

void App::initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    // start_color();
    curs_set(0);
}

void App::shutdownCurses() { endwin(); }

void App::run() {
    int ch;
    bool running = true;
    using clock = std::chrono::steady_clock;

    int refresh_ms = 10 * 100;

    initCurses();
    box(stdscr, 0, 0);
    refresh();

    layout = std::make_unique<Layout>(2, 1);
    SystemStats systemStats = monitor.getSystemStats();

    auto last_updated = clock::now();

    layout->render(systemStats);
    layout->refresh();

    while (running) {
        auto now = clock::now();
        auto elapsed_time =
            std::chrono::duration_cast<std::chrono::milliseconds>(now -
                                                                  last_updated)
                .count();
        if (elapsed_time >= refresh_ms) {
            systemStats = monitor.getSystemStats();
            layout->erase();
            layout->render(systemStats);
            layout->refresh();
            last_updated = now;
        }

        if ((ch = getch()) != EOF) {
            switch (ch) {
            case 'q':
                running = false;
                break;
            default:
                break;
            }
        }

        usleep(5 * 1000);
    }

    shutdownCurses();
}
