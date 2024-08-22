#ifndef MY_STRUCT_H
  #define MY_STRUCT_H

typedef struct s_env {
  char *user;
  char *home;
  char *path[9];
} env_t;

typedef struct s_user_input {
  char *line;
  ssize_t getline_value;
  size_t len;
} user_input_t;

#endif
