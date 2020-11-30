#ifndef RESOURCE_LIMITS_LIMITS_H
#define RESOURCE_LIMITS_LIMITS_H

#include <sys/resource.h>

#define ARRAY_ENTRY(name, x, desc) {#name, desc, x},

struct limit {
    const char *name, *desc;
    int num;
};

#define LIMITS(X)\
    X(RLIMIT_CPU,    0, "Per-process CPU limit, in seconds.")\
    X(RLIMIT_FSIZE,  1, "Largest file that can be created, in bytes.")\
    X(RLIMIT_DATA,   2, "Maximum size of data segment, in bytes.")\
    X(RLIMIT_STACK,  3, "Maximum size of stack segment, in bytes.")\
    X(RLIMIT_CORE,   4, "Largest core file that can be created, in bytes.")\
    X(RLIMIT_NOFILE, 7, "Number of open files.")\
    X(RLIMIT_AS,     9, "Address space limit.")

#endif //RESOURCE_LIMITS_LIMITS_H
