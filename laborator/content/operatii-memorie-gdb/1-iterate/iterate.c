// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

/*
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main(void) {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

    for (int i = 0; i < 5; i++) printf("%p -> 0x%x\n", &v[i], v[i]);
    printf("\n");

    for (int i = 0; i < 9; i++)
        printf(
            "%p -> 0x%04hx\n",
            (char *)v + i * 2,
            *(short *)((char *)v + i * 2));
    printf("\n");

    for (int i = 0; i < 17; i++)
        printf("%p -> 0x%02hhx\n", (char *)v + i, *(char *)((char *)v + i));

    (void)v;

    return 0;
}
