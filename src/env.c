#include "my_header.h"

static size_t get_size_env(char **env) {
  size_t i = 0;

  if (env == NULL)
    return (-1);
  for (; NULL != env[i]; ++i);
  return (i);
}

char **copy_env(char **env) {
  char **my_env;
  size_t size = get_size_env(env);

  if (size == -1)
    return (NULL);
  my_env = malloc(sizeof(char *) * (size + 1));
  if (my_env == NULL)
    return (NULL);
  my_env[size] = NULL;
  for (size_t i = 0; size != i; ++i) {
    my_env[i] = my_strdup(env[i]);
    if (my_env[i] == NULL) {
      free(my_env);
      return (NULL);
    }
  }
  return (my_env);
}
