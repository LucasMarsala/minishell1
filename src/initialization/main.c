#include "my_header.h"

static void display_wrong_prompt(env_t *my_env) {
  write(1, BLUE, 6);
  write(1, my_env->user, my_strlen(my_env->user));
  write(1, GREEN, 8);
  write(1, " -> ", 4);
  write(1, ORANGE, 12);
  write(1, " ✗", 4);
  write(1, RESET " ", 5);
}

static void display_right_prompt(env_t *my_env, char *path) {
  write(1, BLUE, 6);
  write(1, my_env->user, my_strlen(my_env->user));
  write(1, GREEN, 8);
  write(1, " -> ", 4);
  write(1, LIGHT_BLUE, 6);
  write(1, path, my_strlen(path));
  write(1, ORANGE, 12);
  write(1, " ✗", 4);
  write(1, RESET " ", 5);
}

static void get_prompt(env_t *my_env) {
  char pwd[PATH_MAX];
  char *token = NULL;
  char *path = NULL;

  if (getcwd(pwd, sizeof(pwd)) != NULL) {
    token = strtok(pwd, "/");
    while (token != NULL) {
      path = token;
      token = strtok(NULL, "/");
    }
    display_right_prompt(my_env, path);
  } else
    display_wrong_prompt(my_env);
}

void get_shell_input(env_t *my_env, user_input_t *usr_input) {
  signal(SIGINT, SIG_IGN);
  while (usr_input->getline_value != EOF) {
    if (isatty(STDIN_FILENO)) {
      get_prompt(my_env);
      fflush(stdout);
    }
    usr_input->getline_value = getline(&usr_input->line, &usr_input->len, stdin);
    if (usr_input->getline_value != EOF) {
      usr_input = clear_input(usr_input);
      check_commands(my_env, usr_input);
    }
  }
}

int main(int ac, char **av, char **env) {
  env_t *my_env = (env_t *)malloc(sizeof(env_t));
  user_input_t *usr_input = (user_input_t *)malloc(sizeof(user_input_t));

  if (my_env == NULL || usr_input == NULL) {
    write(2, "Error: Could not allocate memory for structures.", 48);
    return (84);
  }
  initialize_shell(my_env, usr_input, env);
  get_shell_input(my_env, usr_input);
  free_shell(my_env, usr_input);
  return (0);
}
