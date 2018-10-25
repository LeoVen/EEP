#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[])
{
    struct sysinfo info;
    int days, hours, mins;

    sysinfo(&info);

    days = info.uptime / 86400;
    hours = (info.uptime / 3600) - (days * 24);
    mins = (info.uptime / 60) - (days * 1440) - (hours * 60);

    printf("Uptime:               %d -> %d days, %d hours, %d minutes, %ld seconds\n", info.uptime, days, hours, mins, info.uptime % 60);
    printf("Total Ram:            %d -> %d Kb\n", info.totalram, info.totalram * info.mem_unit / 1024);
    printf("Free Ram:             %d -> %d Kb\n", info.freeram, info.freeram * info.mem_unit / 1024);
    printf("Memory Unit:          %d\n",info.mem_unit);
    printf("Number of Process:    %d\n", info.procs);
    printf("Number of Processors: %d\n", get_nprocs());
    return 0;
}
