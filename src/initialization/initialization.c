#include "my_header.h"

static void initialize_env(env_t *my_env, char **env) {
  uid_t uid = getuid();
  struct passwd *pw = getpwuid(uid);
  my_env->path[0] = "/usr/bin";
  my_env->path[1] = "/bin";
  my_env->path[2] = "/usr/sbin";
  my_env->path[3] = "/sbin";
  my_env->path[4] = "/usr/games";
  my_env->path[5] = "/usr/local/games";
  my_env->path[6] = "/usr/local/bin";
  my_env->path[7] = "/usr/local/sbin";
  my_env->path[8] = NULL;
  my_env->env_copy = copy_env(env);

  if (getcwd(my_env->pwd, sizeof(my_env->pwd)) == NULL
  || getcwd(my_env->oldpwd, sizeof(my_env->oldpwd)) == NULL)
    perror("Error getting pwd");
  if (pw) {
      my_env->user = pw->pw_name;
      my_env->home = pw->pw_dir;
  }
}

static void initialize_user_input(user_input_t *usr_input) {
  usr_input->line = NULL;
  usr_input->getline_value = 0;
  usr_input->len = 0;
}

void initialize_shell(env_t *my_env, user_input_t *usr_input, char **env) {
  initialize_env(my_env, env);
  initialize_user_input(usr_input);
}
