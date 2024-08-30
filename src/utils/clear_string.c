#include "my_header.h"

static size_t count_spaces_before(char *str) {
  size_t i = 0;

  for (; (' ' == str[i] || '\t' == str[i] || '\n' == str[i])
  && '\0' != str[i]; ++i);
  return (i);
}

static size_t count_trailing_spaces(char *str) {
  size_t i = 0;

  for (size_t len = (my_strlen(str) - 1); 0 != len
    && (' ' == str[len] || '\t' == str[len] || '\n' == str[len]); --len)
    ++i;
  return (i);
}

static char *remove_trailing_spaces(char *str, size_t new_size) {
  char *new_string = malloc(sizeof(char) * (new_size + 1));
  size_t len = my_strlen(str) - 1;

  if (new_string == NULL)
    return (NULL);
  new_string[new_size] = '\0';
  for (; '\0' != str[len] && ' ' == str[len] || '\t' == str[len]; --len);
  for (size_t i = 0; len >= i; ++i)
    new_string[i] = str[i];
  free(str);
  return (new_string);
}

static char *remove_spaces_before(char *str, size_t new_size) {
  char *new_string = malloc(sizeof(char) * (new_size + 1));
  size_t i = 0;

  if (new_string == NULL)
    return (NULL);
  new_string[new_size] = '\0';
  for (; (' ' == str[i] || '\t' == str[i]) && '\0' != str[i]; ++i);
  for (size_t len = 0; '\0' != str[i]; ++len) {
    new_string[len] = str[i];
    ++i;
  }
  free(str);
  return (new_string);
}

static char *clear_string(char *str) {
  size_t sp_bf = count_spaces_before(str);
  size_t tl_sp = count_trailing_spaces(str);

  if (0 < sp_bf)
    str = remove_spaces_before(str, (my_strlen(str) - sp_bf));
  if (0 < tl_sp)
    str = remove_trailing_spaces(str, (my_strlen(str) - tl_sp));
  return (str);
}

user_input_t *clear_input(user_input_t *usr_input) {
  if (1 < my_strlen(usr_input->line)) {
    usr_input->line[usr_input->getline_value - 1] = '\0';
    usr_input->line = clear_string(usr_input->line);
    usr_input->len = my_strlen(usr_input->line);
  } else if (usr_input->line[0] == '\n')
    free(usr_input->line);
  return (usr_input);
}
