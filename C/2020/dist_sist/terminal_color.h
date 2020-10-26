/**
 * Provides specific colors for the terminal
 */

#ifndef TERMINAL_COLOR_H
#define TERMINAL_COLOR_H

#include <stdio.h>

const char *tc_reset(void)
{
#ifdef TC_COLOR
    return "\x1b[0m";
#else
    return "";
#endif
}

const char *tc_red(void)
{
#ifdef TC_COLOR
    return "\x1b[31m";
#else
    return "";
#endif
}

const char *tc_green(void)
{
#ifdef TC_COLOR
    return "\x1b[32m";
#else
    return "";
#endif
}

const char *tc_blue(void)
{
#ifdef TC_COLOR
    return "\x1b[36m";
#else
    return "";
#endif
}

const char *tc_yellow(void)
{
#ifdef TC_COLOR
    return "\x1b[33m";
#else
    return "";
#endif
}

#endif /* TERMINAL_COLOR_H */
