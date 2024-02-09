#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef s21_cat_h_
#define s21_cat_h_

int main(int argc, char *argv[]);
int new_line(char c);
int without_flag(char *filename);
int file_check(char *filename);
int is_empty_line(FILE *file);
int choose_flag(int i, char ch, int p, FILE *file);
int options_b(int i, char ch, FILE *file);
int options_n(int i, char ch);
void option_v(unsigned char ch);
void option_e(char ch);
void option_E(char ch);
int option_s(char ch, int i, FILE *file);
void open_file(int file_count, char *filename[]);
void option_t(char ch);
void option_T(char ch);

#endif
