#ifndef READ_CSV_H
#define READ_CSV_H

#define MAX_FIELDS 1000000

void count_fields_and_split(const char *line, int fields[]);
int convert_into_array(const char *filename, int **array);

#endif

