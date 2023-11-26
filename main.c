#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("iris.csv", "r");
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, f);  // cabeçalho
    free(line);
    line = NULL;
    while (getline(&line, &len, f) != -1) {
        printf("%s", line);
        free(line);
        line = NULL;
    }
    if (line != NULL) free(line);
    fclose(f);

    return 0;
}
