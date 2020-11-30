#ifndef RESOURCE_LIMITS_LIMITS_H
#define RESOURCE_LIMITS_LIMITS_H

#include <sys/resource.h>

#define ARRAY_ENTRY(name, desc) {#name, desc, name},

struct limit {
    const char *name, *desc;
    int num;
};

#define LIMITS(X)\
    X(RLIMIT_CPU,        "Per-process CPU limit, in seconds.")\
    X(RLIMIT_FSIZE,      "Largest file that can be created, in bytes.")\
    X(RLIMIT_DATA,       "Maximum size of data segment, in bytes.")\
    X(RLIMIT_STACK,      "Maximum size of stack segment, in bytes.")\
    X(RLIMIT_CORE,       "Largest core file that can be created, in bytes.") \
    X(RLIMIT_RSS,        "Largest resident set size, in bytes.")             \
    X(RLIMIT_NPROC,      "Number of processes.")             \
    X(RLIMIT_NOFILE,     "Number of open files.")             \
    X(RLIMIT_MEMLOCK,    "Locked-in-memory address space.")             \
    X(RLIMIT_AS,         "Address space limit.")              \
    X(RLIMIT_LOCKS,      "Maximum number of file locks.")\
    X(RLIMIT_SIGPENDING, "Maximum number of pending signals.")\
    X(RLIMIT_MSGQUEUE,   "Maximum bytes in POSIX message queues.")\
    X(RLIMIT_NICE,       "Maximum nice priority allowed to raise to.")\
    X(RLIMIT_RTPRIO,     "Maximum realtime priority allowed for non-priviledged processes.")\
    X(RLIMIT_RTTIME,     "Maximum CPU time in µs that a process scheduled under a real-time"\
                         " scheduling policy may consume at once.")

#endif //RESOURCE_LIMITS_LIMITS_H
