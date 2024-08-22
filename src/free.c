#include "my_header.h"

void free_array(char **array) {
  for (size_t i = 0; NULL != array[i]; ++i)
    free(array[i]);
  free(array);
}

void free_shell(env_t *my_env, user_input_t *usr_input) {
  if (usr_input->line)
    free(usr_input->line);
  free(my_env);
  free(usr_input);
}
