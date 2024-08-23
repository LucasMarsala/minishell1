#ifndef MY_FUNCTIONS_H
  #define MY_FUNCTIONS_H

  #include "my_struct.h"

  ssize_t getline(char **, size_t *, FILE *);
  char *strtok_r(char *, const char *, char **);

  void print_array(char **);
  int my_strstr(const char *, const char *);
  char *my_strdup(const char *);
  size_t my_strlen(const char *);
  char *my_strcat(const char *, const char *);
  char **str_to_word_array(char *);
  int my_strcmp(const char *, const char *);

  char **copy_env(char **);
  void check_commands(env_t *, user_input_t *);
  void initialize_shell(env_t *, user_input_t *, char **);
  void exec_env_command(env_t *);

  void free_shell(env_t *, user_input_t *);
  void free_array(char **);

#endif
