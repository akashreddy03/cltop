#include <cltop/ui/Footer.h>
#include <ncurses.h>

Footer::Footer(int x, int y, int w, int h) : Window(x, y, w, h) {}
void Footer::render() {
    mvwprintw(win, 0, 0, "[q] quit [s] sort [k] kill [h] help");
}
