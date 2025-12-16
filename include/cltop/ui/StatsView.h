#include <cltop/ui/Window.h>
#include <string>

class StatsView : public Window {
  public:
    StatsView(int x, int y, int w, int h);
    void render(float load, double uptime, double cpuPercent);
    std::string formatUptime(double uptime);
};
