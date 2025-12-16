#include <cltop/ui/ProcessTableView.h>
#include <ncurses.h>

ProcessTableView::ProcessTableView(int x, int y, int w, int h)
    : Window(x, y, w, h) {}

void ProcessTableView::render() {
    int y, x;
    getmaxyx(win, y, x);
    mvwprintw(win, 0, 0, "Here will be the processTable %d %d", y, x);
}
