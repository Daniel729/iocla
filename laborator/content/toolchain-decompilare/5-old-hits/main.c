#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int validate(int param_1) {
//     return param_1 == secret + 0x539;
// }
int main() {
    srand(time(NULL));
    int secret = random();
    printf("%d\n", secret + 0x539);
}