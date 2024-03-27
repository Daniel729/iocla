// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

int main(void) {
    int v[] = {1, 2, 15, 51, 53, 66, 202, 7000};
    int dest = v[2]; /* 15 */
    int start = 0;
    int end = sizeof(v) / sizeof(int) - 1;
    int index;
loop:
    if (start >= end) goto end;
    int mid = (start + end) / 2;
    if (v[mid] > dest) goto jump_if_1;
    if (v[mid] < dest) goto jump_if_2;
    index = mid;
    goto end;
jump_if_2:
    start = mid;
    goto loop;
jump_if_1:
    end = mid;
    goto loop;
end:
    printf("%d\n", index);
}
