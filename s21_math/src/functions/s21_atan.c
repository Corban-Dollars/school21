#include "./../s21_math.h"

long double s21_atan(double x) {
  double result = x;
  if (x == 1) result = S21_PI / 4;
  if (x == -1) result = -S21_PI / 4;
  if (s21_fabs(x) < 1) {
    double term = x;
    for (int i = 1; i < 200; i++) {
      term *= (-1) * x * x * (2 * i - 1) / (2 * i + 1);
      result += term;
    }
  } else if (s21_fabs(x) > 1) {
    result = 1. / x;
    double term = 1. / x;
    for (int i = 1; i < 20000; i++) {
      term *= (-1) * (2 * i - 1) / ((2 * i + 1) * x * x);
      result += term;
    }
    if (x > 1) result = S21_PI / 2 - result;
    if (x < -1) result = -S21_PI / 2 - result;
  }
  return result;
}
