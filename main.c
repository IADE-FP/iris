#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iris_records.h"

Record* read_records(const char* filename, int* num_records) {
    FILE* f = fopen(filename, "r");
    char* line = NULL;
    size_t len = 0;
    getline(&line, &len, f);  // cabeçalho
    free(line);
    line = NULL;
    Record* records = NULL;
    *num_records = 0;
    while (getline(&line, &len, f) != -1) {
        line[strlen(line) - 1] = '\0';
        records = realloc(records, (*num_records + 1) * sizeof(Record));
        records[*num_records].sepal_length = atof(strtok(line, ","));
        records[*num_records].sepal_width = atof(strtok(NULL, ","));
        records[*num_records].petal_length = atof(strtok(NULL, ","));
        records[*num_records].petal_width = atof(strtok(NULL, ","));
        char* species = strtok(NULL, ",");
        records[*num_records].species = malloc(sizeof(char) * (strlen(species) + 1));
        strcpy(records[*num_records].species, species);
        (*num_records)++;
        free(line);
        line = NULL;
    }
    if (line != NULL) free(line);
    fclose(f);
    return records;
}

void print_records(Record* records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("%lf %lf %lf %lf %s\n", records[i].sepal_length, records[i].sepal_width, records[i].petal_length, records[i].petal_width, records[i].species);
    }
}

void free_records(Record* records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        free(records[i].species);
    }
    free(records);
}

double mean_species_sepal_length(Record* records, int num_records, const char* species) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].species, species) == 0) {
            sum += records[i].sepal_length;
            count++;
        }
    }
    return sum / count;
}

void write_mean_species_sepal_length(Record* records, int num_records, const char** species, const int num_species, const char* out_filename) {
    FILE* f = fopen(out_filename, "w");
    fprintf(f, "species,mean_sepal_length\n");
    for (int i = 0; i < num_species; i++) {
        double mean = mean_species_sepal_length(records, num_records, species[i]);
        printf("%s mean sepal length: %1.3lf\n", species[i], mean);
        fprintf(f, "%s,%1.3lf\n", species[i], mean);
    }
    fclose(f);
}

int main() {
    int num_records = 0;
    Record* records = read_records("iris.csv", &num_records);

    // print_records(records, num_records);

    const char* species[] = {"setosa", "versicolor", "virginica"};
    char* out_filename = "iris_means.csv";
    write_mean_species_sepal_length(records, num_records, species, 3, out_filename);
    
    free_records(records, num_records);

    return 0;
}
