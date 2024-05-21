void usage(void)

{
    puts("Usage: ./crackme <password>");
    // WARNING: Subroutine does not return
    exit(0);
}

// WARNING: Unknown calling convention

int main(int argc, char **argv)

{
    size_t sVar1;

    if (argc == 2) {
        sVar1 = strlen(argv[1]);
        if ((sVar1 == 8) && (argv[1][3] == 'E')) {
            puts("Good job!");
            // WARNING: Subroutine does not return
            exit(0);
        }
        puts("Try again!");
    } else {
        usage();
    }
    return 0;
}