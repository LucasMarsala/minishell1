#include "my_header.h"

size_t my_strlen(const char *str) {
  size_t i = 0;

  for (; str[i] != '\0'; ++i);
  return (i);
}

size_t my_strstr(const char *s1, const char *s2) {
  size_t len_s2 = my_strlen(s2);
  size_t checkpoint = 0;
  size_t check = 0;

  if (len_s2 == 0 || my_strlen(s1) == 0)
    return (-1);
  for (size_t i = 0; '\0' != s1[i]; ++i) {
    checkpoint = i;
    for (size_t a = 0; '\0' != s2[a] || '\0' != s1[checkpoint]; ++a) {
      if (s1[checkpoint] == s2[a]) {
        checkpoint++;
        check++;
      } else
        break;
    }
    if (check == len_s2)
      return (0);
    check = 0;
  }
  return (-1);
}

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
