#include "my_header.h"

size_t my_strlen(const char *str) {
  size_t i = 0;

  for (; '\0' != str[i]; ++i);
  return (i);
}

int my_strstr(const char *s1, const char *s2) {
  size_t len_s2 = my_strlen(s2);
  size_t checkpoint = 0;
  size_t check = 0;

  if (len_s2 == 0 || my_strlen(s1) == 0)
    return (-1);
  for (size_t i = 0; '\0' != s1[i]; ++i) {
    checkpoint = i;
    for (size_t a = 0; ('\0' != s2[a]) || ('\0' != s1[checkpoint]); ++a) {
      if (s1[checkpoint] == s2[a]) {
        ++checkpoint;
        ++check;
      } else
        break;
    }
    if (check == len_s2)
      return (0);
    check = 0;
  }
  return (-1);
}

char *my_concatstr(const char *s1, const char *s2) {
  char *str = NULL;
  size_t i = 0;
  size_t len = (my_strlen(s1) + my_strlen(s1));
  printf("JE SUIS LEN = %d", len);
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
