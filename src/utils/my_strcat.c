#include "my_header.h"

char *my_strcat(const char *s1, const char *s2) {
  char *str = NULL;
  size_t i = 0;
  size_t len = (my_strlen(s1) + my_strlen(s2));

  if (len == 0)
    return (NULL);
  str = malloc(sizeof(char) * (len + 1));
  if (str == NULL)
    return (NULL);
  str[len] = '\0';
  for (; '\0' != s1[i]; ++i)
    str[i] = s1[i];
  for (size_t a = 0; '\0' != s2[a]; ++a) {
    str[i] = s2[a];
    ++i;
  }
  return (str);
}
