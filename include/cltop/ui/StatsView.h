#include "cltop/data/SystemStats.h"
#include <cltop/ui/Window.h>
#include <string>

class StatsView : public Window {
  public:
    StatsView(int x, int y, int w, int h);
    void render(float load, double uptime, double cpuPercent, MemoryStats ms);
    std::string formatUptime(double uptime);
};
