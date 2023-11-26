#pragma once

typedef struct {
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
    char* species;
} Record;

Record* read_records(const char* filename, int* num_records);
void print_records(Record* records, int num_records);
void free_records(Record* records, int num_records);
double mean_species_sepal_length(Record* records, int num_records, const char* species);
void write_mean_species_sepal_length(Record* records, int num_records, const char** species, const int num_species, const char* out_filename);
