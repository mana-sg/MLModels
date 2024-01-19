#include"read_csv.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
  char *filename = "example.txt";
  int **XY;
  convert_into_array(filename, XY);

  return 0;
}
