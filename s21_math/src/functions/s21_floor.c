#include "./../s21_math.h"

long double s21_floor(double x) {
  long double result;
  if (S21_NAN == s21_fabs(x) || S21_INF == s21_fabs(x)) {
    result = x;
  } else {
    int status = 0;
    result = (long long int)x;
    if (result == x) status = 1;
    if (status == 0) {
      if (x < 0.0) {
        result -= 1;
      }
    }
  }
  return result;
}