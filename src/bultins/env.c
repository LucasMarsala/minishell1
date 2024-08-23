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

  if (0 >= size)
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

static void display_env(env_t *my_env) {
  write(1, "USER=", 5);
  write(1, my_env->user, my_strlen(my_env->user));
  write(1, "\nPATH=", 7);
  for (size_t i = 0; i != 8; ++i) {
    write(1, my_env->path[i], my_strlen(my_env->path[i]));
    if (i != 7)
      write(1, ":", 1);
  }
  write(1, "\nPWD=", 6);
  write(1, my_env->pwd, my_strlen(my_env->pwd));
  write(1, "\nOLDPWD=", 9);
  write(1, my_env->oldpwd, my_strlen(my_env->oldpwd));
  write(1, "\nHOME=", 7);
  write(1, my_env->home, my_strlen(my_env->home));
  write(1, "\n", 1);
}

void exec_env_command(env_t *my_env) {
  if (my_env->env_copy)
    print_array(my_env->env_copy);
  else
    display_env(my_env);
}
