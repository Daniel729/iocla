#include <stdio.h>
#include <stdlib.h>

void print_binary(int number) {
    int pow2 = 0b10000000;
    printf("0b");
    while ( pow2 > 0) {
        if (number >= pow2) {
			printf("1");
            number -= pow2;
        } else
            printf("0");
        pow2 /= 2;
    }
	printf("\n");
}

void check_parity(int *numbers, int n) {
    for (int i = 0; i < n; i++) {
        if (*(numbers + i) & 1) {
            printf("0x%08x\n", *(numbers + i));
        } else {
            print_binary(*(numbers + i));
        }
    }
}

int main(void) {
	int nums[] = {214, 71, 84, 134, 86};
    check_parity(nums, 5);
	return 0;
}
