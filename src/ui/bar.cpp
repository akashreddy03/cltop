#include <cltop/ui/bar.h>
#include <ncurses.h>

void drawBar(WINDOW *win, int x, int y, int width, double percent) {
    wmove(win, y, x);
    int filled = (percent / 100) * width;
    waddch(win, '[');
    for (int i = 0; i < width; i++) {
        if (i < filled) {
            waddch(win, '=');
        } else if (i == filled) {
            waddch(win, '>');
        } else {
            waddch(win, ' ');
        }
    }
    waddch(win, ']');
}
