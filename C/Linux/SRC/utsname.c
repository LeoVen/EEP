#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(int argc, char *argv[])
{
    struct utsname uts;

    uname(&uts);
    printf("Node name:   %s\n", uts.nodename);
    printf("System name: %s\n", uts.sysname);
    printf("Release:     %s\n", uts.release);
    printf("Version:     %s\n", uts.version);
    printf("Machine:     %s\n", uts.machine);

    return 0;
}
