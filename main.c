#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exec(int argc, const char* argv[])
{
    FILE* fout = fopen(argv[1], "w");

    if (fout == NULL) {
        printf("Could not create file!"
               " Do you have write permission in this directory");
    }

    if (argc > 3 || argc == 2) {
        fprintf(fout, "#include <stdio.h>\n");
        for (int i = 3; i < argc; i++) {
            if (strcmp("stdio.h", argv[i]) != 0) {
                fprintf(fout, "#include <%s>\n", argv[i]);
            }
        }
    }

    fprintf(fout, "\nint main(void)\n"
                  "{\n    printf(\"Hello, world!\\n\");\n"
                  "    return 0;\n}\n");

    fclose(fout);
}

int main(int argc, const char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file.c> -i <header1.h> <header2.h> ...\n"
               "Without the angle brackets!\n"
               "stdio.h is included by default\n",
            argv[0]);
        exit(1);
    } else if (argc == 2) {
        exec(argc, argv);
    } else if (argc == 3) {
        printf("Usage: %s <file.c> -i <header1.h> <header2.h> ...\n"
               "Without the angle brackets!\n"
               "stdio.h is included by default\n",
            argv[0]);
        exit(1);
    } else if (strcmp(argv[2], "-i") != 0) {
        printf("Usage: %s <file.c> -i <header1.h> <header2.h> ...\n"
               "Without the angle brackets!\n"
               "stdio.h is included by default\n",
            argv[0]);
        exit(1);
    } else {
        exec(argc, argv);
    }

    return 0;
}
