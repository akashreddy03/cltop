#include <cltop/ui/Layout.h>
#include <ncurses.h>

Layout::Layout(int sv_h, int footer_h)
    : sv(2, 1, COLS - 4, sv_h), ptv(2, sv_h, COLS - 4, LINES - sv_h - footer_h),
      footer(2, LINES - footer_h - 1, COLS - 4, footer_h) {}

Layout::~Layout() {}

void Layout::erase() {
    sv.erase();
    ptv.erase();
    footer.erase();
}

void Layout::refresh() {
    sv.refresh();
    ptv.refresh();
    footer.refresh();
}
void Layout::render(SystemStats SystemStats) {
    // mvprintw(0, 0, "hello");

    // sv.drawBorder();
    // ptv.drawBorder();
    // footer.drawBorder();
    sv.render(SystemStats.load, SystemStats.uptime, SystemStats.cpuPercent);
    ptv.render();
    footer.render();
}
