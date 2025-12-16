#include <cltop/data/SystemMonitor.h>
#include <cltop/data/SystemStats.h>
#include <fstream>

SystemMonitor::SystemMonitor() {}

SystemMonitor::~SystemMonitor() {}

SystemStats SystemMonitor::getSystemStats() {
    SystemStats systemStats;
    systemStats.load = readLoad();
    systemStats.cpu = readCPU();
    systemStats.cpuPercent = computeDeltaCPU(prevCPUStats, systemStats.cpu);
    prevCPUStats = systemStats.cpu;
    systemStats.uptime = readUptime();
    return systemStats;
}

CPUStats SystemMonitor::readCPU() {
    std::ifstream file("/proc/stat");
    CPUStats curr;
    std::string cpu;
    file >> cpu >> curr.user >> curr.nice >> curr.system >> curr.idle >>
        curr.iowait >> curr.irq >> curr.softirq >> curr.steal;
    return curr;
}

double SystemMonitor::computeDeltaCPU(const CPUStats &prev,
                                      const CPUStats &curr) {
    long long prevIdle = prev.idle + prev.iowait;
    long long currIdle = curr.idle + curr.iowait;

    long long prevTotal = prev.user + prev.nice + prev.system + prevIdle +
                          prev.irq + prev.softirq + prev.steal;
    long long currTotal = curr.user + curr.nice + curr.system + currIdle +
                          curr.irq + curr.softirq + curr.steal;

    long long totalDiff = currTotal - prevTotal;
    long long idleDiff = currIdle - prevIdle;

    return (double)(totalDiff - idleDiff) / totalDiff * 100;
}

float SystemMonitor::readLoad() {
    std::ifstream file("/proc/loadavg");
    Load load;
    if (file.is_open()) {
        file >> load.load1 >> load.load5 >> load.load15;
    }

    return load.load1;
}

double SystemMonitor::readUptime() {
    std::ifstream file("/proc/uptime");
    double uptime;
    if (file.is_open()) {
        file >> uptime;
    }
    return uptime;
}
