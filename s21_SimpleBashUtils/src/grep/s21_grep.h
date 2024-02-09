#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef s21_grep_h_
#define s21_grep_h_

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int def;
} flags;

void print_line(char *line);
void option_e(char *line, char *temp, char *filename[], int n, int comp_counter,
              int file_count);
void option_i(char *line, char *temp, char *filename[], int n, int comp_counter,
              int file_count);
void option_v(char *line, char *temp, char *filename[], int n, int comp_counter,
              int file_count);
void option_n(char *line, char *temp, int str_count, char *filename[], int n,
              int comp_counter, int file_count);
void option_h(char *line, char *temp);
int fill_flags(int argc, char **argv, flags *option);
int flags_realise(char *line, flags *option, char *temp, int str_count,
                  int comp_counter, char *filename[], int n, int file_count);
void open_file(char *filename[], flags *option, int n, int file_count);
int main(int argc, char **argv);

#endif
