#include "s21_cat.h"

int new_line(char c) { return (c == '\n'); }
int tab(char c) { return (c == '\t'); }

int flag(char *filename) {
  int q = 0;
  if (filename[0] == 45) {
    if (filename[1] == 'n') q = 1;
    if (filename[1] == 'b') q = 2;
    if (filename[1] == 'v') q = 3;
    if (filename[1] == 'e') q = 4;
    if (filename[1] == 'E') q = 5;
    if (filename[1] == 's') q = 6;
    if (filename[1] == 't') q = 7;
    if (filename[1] == 'T') q = 8;
    char GNU_B[50] = "--number-nonblank";
    if (strcmp(filename, GNU_B) == 0) q = 2;
    char GNU_N[50] = "--number";
    if (strcmp(filename, GNU_N) == 0) q = 1;
    char GNU_S[50] = "--squeeze-blank";
    if (strcmp(filename, GNU_S) == 0) q = 6;

  } else
    q = 0;
  return q;
}

int empty_line(FILE *file) {
  char ch;
  int empty;
  empty = 0;
  ch = getc(file);
  if (new_line(ch)) empty = 1;
  ungetc(ch, file);
  return empty;
}

int choose_flag(int i, char ch, int p, FILE *file) {
  switch (p) {
    case 0:
      putchar(ch);
      break;
    case 1:
      i = options_n(i, ch);
      break;
    case 2:
      i = options_b(i, ch, file);
      break;
    case 3:
      option_v(ch);
      break;
    case 4:
      option_e(ch);
      break;
    case 5:
      option_E(ch);
      break;
    case 6:
      i = option_s(ch, i, file);
      break;
    case 7:
      option_t(ch);
      break;
    case 8:
      option_T(ch);
      break;
  }
  return i;
}

void option_v(unsigned char ch) {
  if (tab(ch)) {
    printf("%c", ch);
  } else if (ch < 32 && ch != '\t' && ch != '\n') {
    ch = ch + 64;
    printf("^%c", ch);
  } else if (ch > 127) {
    ch = ch - 63;
    printf("%c", ch);
  } else {
    printf("%c", ch);
  }
}

int options_b(int i, char ch, FILE *file) {
  if (i == 1 && ch != '\n') {
    printf("%6d\t", i);
    i++;
  }
  if (ch == '\n' && !empty_line(file)) {
    printf("\n%6d\t", i);
    i++;
  } else
    putchar(ch);
  return i;
}

int options_n(int i, char ch) {
  if (i == 1) {
    printf("%6d\t", i);
    i++;
  }
  if (ch == '\n') {
    printf("\n%6d\t", i);
    i++;
  } else
    putchar(ch);

  return i;
}

void option_e(char ch) {
  if (ch == '\n')
    printf("$\n");
  else
    option_v(ch);
}

void option_E(char ch) {
  if (ch == '\n')
    printf("$\n");
  else
    putchar(ch);
}

int option_s(char ch, int i, FILE *file) {
  if (empty_line(file) && new_line(ch)) {
    i++;
    if (i == 3) printf("\n");
  } else {
    i = 1;
    putchar(ch);
  }

  return i;
}

void option_t(char ch) {
  if (tab(ch))
    printf("^I");
  else
    option_v(ch);
}
void option_T(char ch) {
  if (tab(ch))
    printf("^I");
  else
    putchar(ch);
}

void open_file(int q, char *filename[]) {
  int i = 1;
  char ch;
  int p = flag(filename[1]);
  if (file_check(filename[q]) == 1) {
    FILE *file = fopen(filename[q], "r");
    while (!feof(file) && !ferror(file)) {
      ch = fgetc(file);
      if (ch != EOF) {
        i = choose_flag(i, ch, p, file);
      }
    }
    fclose(file);
  } else if (p != 0 && filename[q] != filename[1]) {
    printf("Not entered file\n");
  }
}

int without_flag(char *filename) {
  int i = 0;
  if (filename[0] == 45) i = 1;
  return i;
}

int file_check(char *filename) {
  int check = 0;
  FILE *file = fopen(filename, "r");
  if (file) {
    fclose(file);
    check = 1;
  }
  return check;
}

int main(int argc, char *argv[]) {
  if (argc == 1) printf("Not entered flag and file!\n");
  if (argc == 2 && without_flag(argv[1]) == 1)
    printf("Not entered flag or/and file!\n");
  if (argc == 2 && without_flag(argv[1]) == 0 && file_check(argv[1]) == 0)
    printf("Not entered flag or/and file!\n");
  for (int i = 1; i < argc; i++) {
    open_file(i, argv);
  }
  return 0;
}
