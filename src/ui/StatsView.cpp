#include <cltop/ui/StatsView.h>
#include <iomanip>
#include <ncurses.h>
#include <sstream>
#include <string>

StatsView::StatsView(int x, int y, int w, int h) : Window(x, y, w, h) {}

std::string StatsView::formatUptime(double uptime) {
    std::ostringstream ss;

    long seconds = static_cast<long>(uptime);

    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    ss << std::setw(2) << std::setfill('0') << h << ":" << std::setw(2) << m
       << ":" << std::setw(2) << s;
    return ss.str();
}

void StatsView::render(float load, double uptime, double cpuPercent) {
    int y, x;
    getmaxyx(win, y, x);
    mvwprintw(win, 0, 0, "CPU %.2lf%%", cpuPercent);
    mvwprintw(win, 0, (x / 4), "MEM");
    mvwprintw(win, 0, (2 * x / 4), "LOAD %.3f", load);
    mvwprintw(win, 0, 3 * x / 4, "UPTIME %s", formatUptime(uptime).c_str());
}
