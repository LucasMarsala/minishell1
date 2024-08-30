#include "my_header.h"

static size_t count_words(char *str) {
  size_t count = 0;
  size_t check = 0;

  if (str == NULL)
    return (-1);
  for (size_t i = 0; '\0' != str[i]; ++i) {
    if (' ' == str[i] || '\t' == str[i]) {
      if (check == 0) {
        ++count;
        check = 1;
      }
    } else
      check = 0;
  }
  if (0 == count && 0 < my_strlen(str))
    return (1);
  else if (0 < count && 0 < my_strlen(str))
    return (count + 1);
  return (count);
}

static size_t *count_size_words(size_t *size_words, char *str, size_t words) {
  size_t count = 0;
  size_t check = 0;
  size_t line = 0;
  size_t last_size = 0;

  for (size_t i = 0; '\0' != str[i]; ++i) {
    if (' ' != str[i] && '\t' != str[i]) {
      ++count;
      check = 1;
    } else {
      if (check == 1 && words >= line) {
        size_words[line] = count - last_size;
        last_size = count;
        ++line;
        check = 0;
      }
    }
  }
  size_words[line] = count - last_size;
  return (size_words);
}

static char **fill_array(char **array, char *str) {
  size_t check = 0;
  size_t caracter = 0;
  size_t line = 0;

  for (size_t i = 0; '\0' != str[i]; ++i) {
    if (' ' != str[i] && '\t' != str[i]) {
      array[line][caracter] = str[i];
      ++caracter;
      check = 1;
    } else {
      if (check == 1) {
        ++line;
        check = 0;
        caracter = 0;
      }
    }
  }
  return (array);
}

static char **initialize_array(char **array, char *str, size_t words) {
  size_t *size_words = malloc(sizeof(size_t) * (words + 1));

  if (size_words == NULL)
    return (NULL);
  size_words[words] = -1;
  size_words = count_size_words(size_words, str, words);
  array = malloc(sizeof(char *) * (words + 1));
  if (array == NULL) {
    free(size_words);
    return (NULL);
  }
  array[words] = NULL;
  for (size_t i = 0; -1 != size_words[i]; ++i) {
    array[i] = malloc(sizeof(char) * (size_words[i] + 1));
    if (array[i] == NULL) {
      free(size_words);
      free(array);
      return (NULL);
    }
    array[i][size_words[i]] = '\0';
  }
  free(size_words);
  return (array);
}

char **str_to_word_array(char *str) {
  size_t words = count_words(str);
  char **array = NULL;

  if (words == 0 || words == -1)
    return (NULL);
  array = initialize_array(array, str, words);
  if (array == NULL)
    return (NULL);
  array = fill_array(array, str);
  return (array);
}
