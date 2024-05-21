#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str) {
    /* TODO */

    /**
     * The cast to (void) is used to avoid a compiler warning. Remove the line
     * below to find out what the warning is.
     *
     * Remove this cast when implementing the function.
     */

	int len = 0;
	
	while (*(str+len) != 0) len++;

    return len;
}

void equality_check(const char *str) {
    const int len = my_strlen(str);

	for (int i = 0; i < len; i++) {
		int index = 1;
		for (int j = 0; j < i; j++) {
			index *= 2;
			index %= len;
		}
		index += i;
		index %= len;
		if (*(str+index) == *(str + i)) {
			printf("Address of %c: %p\n", *(str+i), str+i);
		}
	}
}

int main(void) {
	char sir[] = "ababababacccbacbacbacbacbabc";

	printf("length = %d\n", my_strlen(sir));
	equality_check(sir);
    return 0;
}
