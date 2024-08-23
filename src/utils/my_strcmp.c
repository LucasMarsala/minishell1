#include "my_header.h"

int my_strcmp(const char *s1, const char *s2) {
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  for (size_t i = 0; '\0' != s1[i]; ++i)
    if (s1[i] != s2[i])
      return (-1);
  return (0);
}
