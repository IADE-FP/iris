#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
    char* species;
} Record;

int main() {
    FILE *f = fopen("iris.csv", "r");
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, f); // cabeçalho
    free(line); line = NULL;
    Record* records = NULL;
    int num_records = 0;
    while(getline(&line, &len, f) != -1) {
        printf("%s", line);
        line[strlen(line) - 1] = '\0';
        records = realloc(records, (num_records + 1) * sizeof(Record));
        records[num_records].sepal_length = atof(strtok(line, ","));
        records[num_records].sepal_width = atof(strtok(NULL, ","));
        records[num_records].petal_length = atof(strtok(NULL, ","));
        records[num_records].petal_width = atof(strtok(NULL, ","));
        char* species = strtok(NULL, ",");
        records[num_records].species = malloc(sizeof(char) * (strlen(species) + 1));
        strcpy(records[num_records].species, species);
        num_records++;
        free(line);
        line = NULL;
    }
    if(line != NULL) free(line);
    fclose(f);

    for (int i = 0; i < num_records; i++) {
        printf("%lf %lf %lf %lf %s\n", records[i].sepal_length, records[i].sepal_width, records[i].petal_length, records[i].petal_width, records[i].species);
    }

    for (int i = 0; i < num_records; i++) {
        free(records[i].species);
    }
    free(records);
    return 0;
}
