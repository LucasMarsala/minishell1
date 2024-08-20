#include "my_header.h"

static size_t count_commands(char *str) {
  size_t i = 0;
  char *token = NULL;

  token = strtok(str, " ");
  while (token != NULL) {
    token = strtok(NULL, " ");
    ++i;
  }
  return (i);
}

static char *get_path_exec(char **env) {
  for (size_t i = 0; NULL != env[i]; ++i)
    if (my_strstr(env[i], "PATH=") == 0 && env[i][0] == 'P')
      return (env[i]);
  return (NULL);
}

static size_t count_pathname(char *str) {
  char *token = NULL;
  size_t i = 0;

  token = strtok(str, ":");
  while (token != NULL) {
    token = strtok(NULL, ":");
    ++i;
  }
  return (i);
}

static char **fill_path(char **my_path, char *str) {
  char *token = NULL;
  size_t i = 0;

  token = strtok(str, ":");
  while (token != NULL) {
    token = strtok(NULL, ":");
    my_path[i] = my_strdup(token);
    ++i;
  }
  return (my_path);
}


void check_commands(char *str, char **env) {
  size_t len = 0;
  char *path = get_path_exec(env);
  char **my_path = NULL;

  if (path == NULL)
    return;
  len = count_pathname(path);
  my_path = malloc(sizeof(char *) * (len + 1));
  if (my_path == NULL)
    return;
  my_path = fill_path(my_path, path);
  my_path[len] = NULL;
  for (int i = 0; my_path[i] != NULL; ++i)
    printf("%s\n", my_path[i]);
  return;
}
