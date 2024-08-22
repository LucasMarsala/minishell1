#include "my_header.h"


static char *remove_trailing_space(char *str) {
  size_t len = strlen(str);

  for (; 0 <= len && ' ' == str[len - 1]; --len)
    str[len] = '\0';
  str[len] = '\0';
  return (str);
}

static int remove_space_before(char **str) {
  for (size_t i = 0; (' ' == *str[i] || '\t' == *str[i])
  && '\0' != *str[i]; ++(*str));
  return (strlen(*str));
}

static size_t count_words(char *str) {
  size_t count = 0;
  size_t check = 0;

  if (remove_space_before(&str) == 0)
    return (0);
  str = remove_trailing_space(str);
  for (size_t i = 0; '\0' != str[i]; ++i) {
    if (' ' == str[i] || '\t' == str[i]) {
      if (check == 0) {
        ++count;
        check = 1;
      }
    } else
      check = 0;
  }
  if (0 == count && 0 < strlen(str))
    return (1);
  else if (0 < strlen(str) && 0 < count)
    return (count + 1);
  return (count);
}

char **str_to_word_array(char *str) {
  char *temp = str;
  size_t words = count_words(str);
  char **array = NULL;
  char *token = NULL;

  if (words == 0)
    return (NULL);
  array = malloc(sizeof(char *) * (words + 1));
  if (array == NULL)
    return (NULL);
  array[words] = NULL;
  token = strtok(str, " ");
  for (size_t i = 0; NULL != token; ++i) {
    array[i] = my_strdup(token);
    token = strtok(NULL, " ");
  }
  return (array);
}
