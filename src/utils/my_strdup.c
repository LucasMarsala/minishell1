#include "my_header.h"

char *my_strdup(const char *str) {
  size_t len = my_strlen(str);
  size_t i = 0;
  char *dest = NULL;

  if (len == 0)
    return (NULL);
  dest = malloc(sizeof(char) * (len + 1));
  if (dest == NULL)
    return (NULL);
  for (; '\0' != str[i]; ++i)
    dest[i] = str[i];
  dest[i] = '\0';
  return (dest);
}
