// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_first(char *s, char *pattern) {
    int is = 0;
    while (s[is] != 0) {
        int ip = 0;
        while (pattern[ip] != 0) {
            if (s[is + ip] == pattern[ip])
                ip++;
            else
                break;
        }

        if (pattern[ip] == 0) {
            while (s[is + ip] != 0) {
                s[is] = s[is + ip];
                is++;
            }
            s[is] = 0;
            break;
        }
        is++;
    }
    return s;
}

int main(void) {
    /*
     * TODO: Este corectă declarația variabilei s în contextul în care o să
     * apelăm funcția delete_first asupra sa? De ce? Modificați dacă este cazul.
     */
    char s[] = "Ana are mere";
    char pattern[] = "re";

    // Decomentați linia după ce ați implementat funcția delete_first.
    printf("%s\n", delete_first(s, pattern));

    return 0;
}
