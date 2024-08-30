#include "my_header.h"

void print_array(char **array) {
  for (int i = 0; array[i] != NULL; ++i)
    printf("STR[%d] = %s\n", i, array[i]);
}
