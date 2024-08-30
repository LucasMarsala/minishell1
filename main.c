#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *str = malloc(sizeof(char) * 10);

  if (str == NULL)
    return (84);
  for (int i = 0; i != 10; ++i)
    str[i] = 'i';
  for (int i = 0; i != 5; ++i)
    ++str;
  free(str);
  return (0);
}
