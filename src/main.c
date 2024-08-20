#include "my_header.h"

static void display_prompt(void) {
  char pwd[PATH_MAX];
  char *token = NULL;
  char *path = NULL;

  if (getcwd(pwd, sizeof(pwd)) != NULL) {
    token = strtok(pwd, "/");
    while (token != NULL) {
      path = token;
      token = strtok(NULL, "/");
    }
    printf(GREEN "->" LIGHT_BLUE " %s " ORANGE "✗ " RESET, path);
  } else
    printf(GREEN "->" ORANGE "✗ " RESET);
}

void print_env(char **env) {
  for (int i = 0; env[i] != NULL; ++i)
    printf("%s\n", env[i]);
  printf("\n\n\n");
}

int main(int ac, char **av, char **env) {
  char *line = NULL;
  ssize_t getline_value = 0;
  size_t len = 0;
  char **my_env = copy_env(env);

  if (my_env == NULL)
    return (-1);
  while (getline_value != EOF) {
    if (isatty(STDIN_FILENO)) {
      display_prompt();
      fflush(stdout);
    }
    getline_value = getline(&line, &len, stdin);
    check_commands(line, my_env);
  }
  if (line)
    free(line);
  free_array(my_env);
  return (0);
}
