#include "my_header.h"


size_t count_commands(char *str) {
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
  for (size_t i = 0; NULL != env[i]; ++i) {
    if (my_strstr(env[i], "PATH=") == 0)
      printf("%s\n", env[i]);
  }
  return (NULL);
}

void check_commands(char *str, char **env) {
  char *token = NULL;
  char *path = get_path_exec(env);
  size_t i = count_commands(str);

  token = strtok(str, " ");
  while (token != NULL) {
    token = strtok(NULL, "/");
  }
  return;
}
