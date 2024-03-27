// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

int main(void) {
    const int len = 8;
    int v[] = {4, 1, 2, -17, 15, 22, 6, 2};
    int max;
    int i;

    max = v[0];
    i = 1;

loop:
    if (i == len) goto end;

    if (max > v[i]) goto cond_false;
    max = v[i];
cond_false:
    i++;
    goto loop;
end:

    printf("%d\n", max);
}
