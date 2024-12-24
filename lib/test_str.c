#include "test.h"

void test_strlen(void)
{
  int is_fail = 0;

  for (int i = 0; i < g_ncases; ++i) {
    char* string = g_cases[i].string;

    if (strlen(string) == ft_strlen(string)) {
      continue;
    }
    is_fail = 1;
    break;
  }
  TEST_RESULT(is_fail);
}

void test_strcpy(void)
{
  char buffer1[1024];
  char buffer2[1024];
  int is_fail = 0;

  for (int i = 0; i < g_ncases; ++i) {
    const char* string = g_cases[i].string;

    if (string == g_long_string) {
      continue;
    }
    strcpy(buffer1, string);
    ft_strcpy(buffer2, string);
    if (strcmp(buffer1, buffer2) == 0) {
      continue;
    }
    is_fail = 1;
    break;
  }
  TEST_RESULT(is_fail);
}

void test_strcmp(void)
{
  int is_fail = 0;

  for (int i = 0; i < g_ncases; ++i) {
    for (int j = 0; j < g_ncases; ++j) {
      char* s0 = g_cases[i].string;
      char* s1 = g_cases[j].string;

      if (strcmp(s0, s1) == ft_strcmp(s0, s1)) {
        continue;
      }
      is_fail = 1;
      break;
    }
  }
  TEST_RESULT(is_fail);
}

void test_strdup(void)
{
  int is_fail = 0;

  for (int i = 0; i < g_ncases; ++i) {
    char* string = g_cases[i].string;
    char* p0 = strdup(string);
    char* p1 = ft_strdup(string);
    int result = strcmp(p0, p1) == 0 && ft_strcmp(p0, p1) == 0;

    free(p0);
    free(p1);
    if (result) {
      continue;
    }
    is_fail = 1;
    break;
  }
  TEST_RESULT(is_fail);
}
