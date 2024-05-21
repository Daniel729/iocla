#include <stdio.h>

void rotate_left(unsigned int *number, int bits) {
    for (int i = 0; i < bits; i++) *number *= 2;
}

void rotate_right(unsigned int *number, int bits) {
    for (int i = 0; i < bits; i++) *number /= 2;
}

int main(void) {
    unsigned int num1 = 0x00001234;
    unsigned int num2 = 0x12340000;

    rotate_left(&num1, 4);
    rotate_right(&num2, 4);
    printf("%08x\n%08x\n", num1, num2);

    return 0;
}
