#ifndef MY_FUNCTIONS_H
  #define MY_FUNCTIONS_H

  #include "my_struct.h"

  ssize_t getline(char **, size_t *, FILE *);
  char *strtok_r(char *, const char *, char **);

  char **copy_env(char **);
  void print_array(char **);
  void free_array(char **);
  int my_strstr(const char *, const char *);
  size_t my_strlen(const char *);
  char *my_strdup(const char *);
  void check_commands(env_t *, user_input_t *, char **);
  char *my_strcat(const char *, const char *);
  void initialize_shell(env_t *, user_input_t *);
  void free_shell(env_t *, user_input_t *);
  char **str_to_word_array(char *);

#endif
