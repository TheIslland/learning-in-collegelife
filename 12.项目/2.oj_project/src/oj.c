#include <stdio.h>
#include "run.h"

int main()
{
    const char *name_program = "./program";
    const char *name_in = "./in.txt";
    const char *name_out = "./out.txt";
    const char *name_right = "./right.txt";
    run(name_program, name_in, name_out);
    FILE *fpright = fopen(name_right, "r");
    FILE *fpout = fopen(name_out, "r");
    char c1, c2;
    while ((c1 = fgetc(fpright), c2 = fgetc(fpout), c1 != EOF && c2 != EOF && c1 == c2)) ;
    if (c1 != EOF && c2 != EOF) {
        printf("Wrong Answer\n");
    } else if (c1 == c2) {
        printf("Accept\n");
    } else {
        if (c1 != '\n' && c2 != '\n') {
            printf("Wrong Answer\n");
        } else {
            c1 == EOF ? (c2 = fgetc(fpout)) : (c1 = fgetc(fpright));
            printf("%s\n", c1 == c2 ? "Accept" : "Wrong Answer");
        }
    }
    fclose(fpout);
    fclose(fpright);
    return 0;
}
