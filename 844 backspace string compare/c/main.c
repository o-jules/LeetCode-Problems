#include <string.h>
// #include <boolean.h>
#include <stdio.h>

#define bool int

bool backspaceCompare(char* S, char* T);

bool backspaceCompare(char* S, char* T) {
  int s_len = strlen(S);
  int t_len = strlen(T);

  char s_cache[s_len];
  char t_cache[t_len];

  strcpy(s_cache, S);
  strcpy(t_cache, T);

  int del_count = 0;
  int i;

  int s_size = 0;
  i = s_len - 1;
  for (; i >= 0; i--) {
    if ('#' == S[i]) {
      del_count ++;
    } else {
      if (del_count > 0) {
        del_count --;
      } else {
        s_cache[s_size] = S[i];
        s_size++;
      }
    }
  }
  s_cache[s_size] = '\0';

  int t_size = 0;
  i = t_len - 1;
  del_count = 0;
  for (; i >= 0; i--) {
    if ('#' == T[i]) {
      del_count ++;
    } else {
      if (del_count > 0) {
        del_count --;
      } else {
        t_cache[t_size] = T[i];
        t_size++;
      }
    }
  }
  t_cache[t_size] = '\0';

  return s_size == t_size && strcmp(s_cache, t_cache) == 0;
}

int main(int argc, char **args) {
  if (argc >= 3) {
    char *s1 = args[1];
    char *s2 = args[2];

    if (backspaceCompare(s1, s2)) {
      printf("yes!\n");
    } else {
      printf("no!\n");
    }
  }
}
