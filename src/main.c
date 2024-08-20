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

int main (int ac, char **av, char **env) {
  char *line = NULL;
  ssize_t getline_value = 0;
  size_t len = 0;

  while (getline_value != EOF) {
    if (isatty(STDIN_FILENO)) {
      display_prompt();
      fflush(stdout);
    }
    getline_value = getline(&line, &len, stdin);
    printf("%s", line);
  }
  if (line)
    free(line);
  return (0);
}
