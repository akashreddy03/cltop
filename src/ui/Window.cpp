#include <cltop/ui/Window.h>
#include <ncurses.h>

Window::Window(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
    win = newwin(h, w, y, x);
    // mvprintw(y, x, "%d %d %d %d", x, y, w, h);
}

void Window::refresh() { wrefresh(win); }

void Window::drawBorder() { box(win, 0, 0); }

void Window::erase() { werase(win); }

Window::~Window() {
    if (win) {
        delwin(win);
    }
}
