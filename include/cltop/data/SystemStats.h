#pragma once

struct Load {
    float load1;
    float load5;
    float load15;
};

struct CPUStats {
    long long user, nice, system, idle, iowait, irq, softirq, steal;
};

struct SystemStats {
    CPUStats cpu;
    double cpuPercent;
    float mem;
    float swap;
    float load;
    float uptime;
};
