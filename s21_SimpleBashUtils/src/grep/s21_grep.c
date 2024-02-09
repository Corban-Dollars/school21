#include "s21_grep.h"

void print_line(char *line) { printf("%s", line); }

void option_e(char *line, char *temp, char *filename[], int n, int comp_counter,
              int file_count) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_EXTENDED);
  if ((regexec(&re_temp, line, 0, NULL, 0) == 0) && file_count == 1) {
    print_line(line);
  } else if ((regexec(&re_temp, line, 0, NULL, 0) == 0) && file_count > 1 &&
             comp_counter > 0)
    printf("%s:%s", filename[n], line);
  regfree(&re_temp);
}

void option_i(char *line, char *temp, char *filename[], int n, int comp_counter,
              int file_count) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_ICASE);
  if ((regexec(&re_temp, line, 0, NULL, 0) == 0) && file_count == 1) {
    print_line(line);
  } else if ((regexec(&re_temp, line, 0, NULL, 0) == 0) && file_count > 1 &&
             comp_counter > 0)
    printf("%s:%s", filename[n], line);
  regfree(&re_temp);
}

void option_v(char *line, char *temp, char *filename[], int n, int comp_counter,
              int file_count) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_EXTENDED);
  if ((regexec(&re_temp, line, 0, NULL, 0) != 0) && file_count == 1) {
    print_line(line);
  } else if ((regexec(&re_temp, line, 0, NULL, 0) != 0) && file_count > 1 &&
             comp_counter > 0)
    printf("%s:%s", filename[n], line);
  regfree(&re_temp);
}

void option_n(char *line, char *temp, int str_count, char *filename[], int n,
              int comp_counter, int file_count) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_EXTENDED);
  if ((regexec(&re_temp, line, 0, NULL, 0) == 0) && file_count == 1) {
    printf("%d:%s", str_count, line);
  } else if ((regexec(&re_temp, line, 0, NULL, 0) == 0) && file_count > 1 &&
             comp_counter > 0)
    printf("%s:%d:%s", filename[n], str_count, line);
  regfree(&re_temp);
}

void option_h(char *line, char *temp) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_EXTENDED);
  if (regexec(&re_temp, line, 0, NULL, 0) == 0) printf("%s", line);
  regfree(&re_temp);
}

int fill_flags(int argc, char **argv, flags *option) {
  char opt;
  while ((opt = getopt(argc, argv, "ivclneh")) != -1) {
    switch (opt) {
      case 'e':
        option->e = 1;
        break;
      case 'i':
        option->i = 1;
        break;
      case 'v':
        option->v = 1;
        break;
      case 'c':
        option->c = 1;
        break;
      case 'l':
        option->l = 1;
        break;
      case 'n':
        option->n = 1;
        break;
      case 'h':
        option->h = 1;
        break;
      default:
        option->def = 1;
    }
  }
  return optind;
}

int flags_realise(char *line, flags *option, char *temp, int str_count,
                  int comp_counter, char *filename[], int n, int file_count) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_EXTENDED);
  if (regexec(&re_temp, line, 0, NULL, 0) == 0) {
    if (option->l) comp_counter++;
    if (option->c) comp_counter++;
  }
  if (option->e) {
    comp_counter++;
    option_e(line, temp, filename, n, comp_counter, file_count);
  }
  if (option->i) {
    comp_counter++;
    option_i(line, temp, filename, n, comp_counter, file_count);
  }
  if (option->v) {
    comp_counter++;
    option_v(line, temp, filename, n, comp_counter, file_count);
  }
  if (option->n) {
    comp_counter++;
    option_n(line, temp, str_count, filename, n, comp_counter, file_count);
  }
  if (option->h) {
    option_h(line, temp);
  }
  regfree(&re_temp);
  return comp_counter;
}

void open_file(char *filename[], flags *option, int n, int file_count) {
  FILE *file = NULL;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int str_count = 0;
  int comp_counter = 0;
  if (filename[n] != NULL) {
    file = fopen(filename[n], "r");
  }
  if (file == NULL) exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, file)) != -1) {
    str_count++;
    comp_counter = flags_realise(line, option, filename[2], str_count,
                                 comp_counter, filename, n, file_count);
  }
  if (option->l && comp_counter > 0) printf("%s\n", filename[n]);
  if (option->c && comp_counter > 0 && file_count == 1) {
    printf("%d\n", comp_counter);
  } else if (option->c && comp_counter > 0 && file_count > 1) {
    printf("%s.%d\n", filename[n], comp_counter);
  }
  if (option->v) printf("\n");
  free(line);
  fclose(file);
}

int main(int argc, char **argv) {
  flags option = {0};
  int i = fill_flags(argc, argv, &option);
  int file_count = argc - (i + 1);
  for (int n = i + 1; n <= argc; n++) {
    open_file(argv, &option, n, file_count);
  }
  return 0;
}