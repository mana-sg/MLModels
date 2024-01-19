#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_csv.h"


void count_fields_and_split(const char *line, int fields[]) {
    int count = 0;

    char *token = strtok((char *)line, ",");
    while (token != NULL && count < MAX_FIELDS) {
        fields[count++] = atoi(token);
        token = strtok(NULL, ",");
    }
}

int convert_into_array(const char *filename, int **array){
  FILE *file = fopen(filename, "r");
  if (!file) {
  perror("Error opening file");
  return 1;
  }
  char line[10000000];
  int line_count = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    line_count++;
    count_fields_and_split(line, array[line_count]);
  }
  fclose(file);
  
  return line_count;
}


