#ifndef MY_FUNCTIONS_H
  #define MY_FUNCTIONS_H

  ssize_t getline(char **, size_t *, FILE *);
  char **copy_env(char **);
  void free_env(char **);
  size_t my_strstr(const char *, const char *);
  size_t my_strlen(const char *);
  char *my_strdup(const char *);
  char *strtok_r(char *, const char *, char **);
  void check_commands(char *, char **);

#endif
