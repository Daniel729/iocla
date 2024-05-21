#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mirror(char *s) {
    int len = strlen(s);

    for (int i = 0; i < len - i - 1; i++) {
        char aux = *(s + i);
        *(s + i) = *(s + len - i - 1);
        *(s + len - i - 1) = aux;
    }
}

int main(void) {
    char str[] = "AnaAreMere";
    mirror(str);
    printf("%s\n", str);
    return 0;
}
