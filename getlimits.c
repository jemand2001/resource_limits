#include <sys/resource.h>

#include <stdio.h>
#include <string.h>

#include "limits.h"

int max_name();
struct limit limits[] = {
        LIMITS(ARRAY_ENTRY)
};

size_t limits_num = sizeof(limits) / sizeof(struct limit);

int main() {
    struct rlimit the_limit;
    int name_cols = max_name();
    printf("%-*s | %-20s | %-20s | description\n", name_cols, "resource name", "soft limit", "hard limit");
    for (int i = 0; i < limits_num; i++) {
        getrlimit(limits[i].num, &the_limit);
        printf("%-*s | %20lu | %20lu | %s\n", name_cols, limits[i].name, the_limit.rlim_cur, the_limit.rlim_max, limits[i].desc);
    }
    return 0;
}

int max_name() {
    int res = 0, new_res;
    for (int i = 0; i < limits_num; i++) {
        if ((new_res = (int) strlen(limits[i].name)) > res)
            res = new_res;
    }
    return res;
}
