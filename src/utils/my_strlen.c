#include "my_header.h"

size_t my_strlen(const char *str) {
  size_t i = 0;

  for (; '\0' != str[i]; ++i);
  return (i);
}
