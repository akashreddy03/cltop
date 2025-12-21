#include <cltop/data/SystemStats.h>

class SystemMonitor {
  public:
    SystemMonitor();
    ~SystemMonitor();

    SystemStats getSystemStats();

  private:
    CPUStats prevCPUStats;
    double computeDeltaCPU(const CPUStats &prev, const CPUStats &curr);
    CPUStats readCPU();
    MemoryStats readMemory();
    double readUptime();
    float readLoad();
};
