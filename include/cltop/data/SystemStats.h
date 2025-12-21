#pragma once

struct Load {
    float load1;
    float load5;
    float load15;
};

struct CPUStats {
    long long user, nice, system, idle, iowait, irq, softirq, steal;
};

struct MemoryStats {
    long memTotal, memFree, memAvailable, memUsed;
};

struct SystemStats {
    CPUStats cpu;
    double cpuPercent;
    MemoryStats mem;
    float swap;
    float load;
    float uptime;
};
