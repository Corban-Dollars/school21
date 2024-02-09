#include "./../s21_math.h"

long double s21_int_pow(double base, double exp) {
  long double result = 1;
  for (int i = 0; i < exp; i++) {
    result *= base;
  }
  return result;
}

long double s21_pow(double base, double exponent) {
  long double result;
  if (exponent == S21_INF && s21_fabs(base) > 1)
    result = S21_INF;
  else if (exponent == S21_INF && s21_fabs(base) == 1)
    result = 1;
  else if (exponent == S21_INF && s21_fabs(base) < 1)
    result = 0.0;
  else if (exponent == -S21_INF && s21_fabs(base) > 1)
    result = 0;
  else if (exponent == -S21_INF && s21_fabs(base) == 1)
    result = 1;
  else if (exponent == -S21_INF && s21_fabs(base) < 1)
    result = S21_INF;
  else if (base == -S21_INF && exponent == 1)
    result = -S21_INF;
  else if (s21_fabs(base) == S21_INF && exponent == -1)
    result = 0;
  else if (s21_fabs(base) == S21_INF && exponent > 0)
    result = S21_INF;
  else if (s21_fabs(base) == S21_INF && exponent < 0)
    result = 0;
  else if (s21_fabs(base) == S21_INF && s21_fabs(exponent) == 0)
    result = 1.0;
  else if (exponent == 0)
    result = 1;
  else if ((int)base == base && base < 0 && (int)exponent == exponent) {
    result = s21_int_pow(base, s21_fabs(exponent));
    if (exponent < 0) result = 1. / result;
  } else if (base < 0)
    result = S21_NAN;
  else
    result = s21_exp(
        exponent *
        s21_log(
            base));  // плохо считает при base около нуля и при многом другом
  return result;
}