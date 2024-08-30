#include "my_header.h"

static void display_command_not_found(const char *str) {
  write(2, BLUE "minishell1: " RED "command not found: ", 44);
  write(2, str, my_strlen(str));
  write(2, RED, 6);
  write(2, RESET "\n", 6);
}

static int exec_commands(env_t *my_env, char **commands_array, char *path) {
  pid_t pid;
  static char *newenviron[] = { NULL };

  pid = fork();
  if (pid < 0) {
    perror("Fork failed.");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    execve(path, commands_array, newenviron);
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
  return 0;
}

static char *check_commands_with_env(env_t *my_env, char **commands) {
  char *str = NULL;
  char *temp = NULL;
  size_t len = 0;

  if (commands == NULL)
    return (NULL);
  for (size_t i = 0; NULL != my_env->path[i]; ++i) {
    temp = my_strcat(my_env->path[i],"/");
    str = my_strcat(temp, commands[0]);
    if (str == NULL || temp == NULL)
      return (NULL);
    if (access(str, F_OK) == 0) {
      free(temp);
      return (str);
    } else if (access(commands[0], F_OK) == 0) {
      free(temp);
      free(str);
      return (my_strdup(commands[0]));
    }
    free(temp);
    free(str);
  }
  return (NULL);
}

static int check_bultins(env_t *my_env, char **commands_array) {
  if (my_strcmp("env", commands_array[0]) == 0) {
    exec_env_command(my_env);
    return (0);
  }
  return (-1);
}

void check_commands(env_t *my_env, user_input_t *usr_input) {
  char **commands_array = str_to_word_array(usr_input->line);
  char *path = check_commands_with_env(my_env, commands_array);

  if (commands_array == NULL)
    return;
  if (check_bultins(my_env, commands_array) == 0) {
    free_array(commands_array);
    free(path);
    return;
  }
  if (path != NULL) {
    if (exec_commands(my_env, commands_array, path) == 0)
      free(path);
  } else
    display_command_not_found(commands_array[0]);
  if (commands_array != NULL)
    free_array(commands_array);
}
