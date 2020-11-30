#include <sys/resource.h>

#include <stdio.h>
#include <string.h>

#include "limits.h"

struct limit limits[] = {
        LIMITS(ARRAY_ENTRY)
};

size_t limits_num = sizeof(limits) / sizeof(struct limit);

int main() {
    struct rlimit the_limit;
    printf("%-15s\t%-20s\t%-20s\tdescription\n", "resource name", "soft limit", "hard limit");
    for (int i = 0; i < limits_num; i++) {
        getrlimit(limits[i].num, &the_limit);
        printf("%-15s\t%20lu\t%20lu\t%s\n", limits[i].name, the_limit.rlim_cur, the_limit.rlim_max, limits[i].desc);
    }
    return 0;
}
