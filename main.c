#include <stdbool.h>

#include "iris_records.h"

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
