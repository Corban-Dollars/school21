#include "./../s21_math.h"

long double s21_fmod(double x, double y) {
  long double answer = 0;
  if (x == 0.0 && y != 0) {
    answer = 0.0;
  } else if (y != 0) {
    if (x < 0 && y < 0)
      answer = s21_abs(x / y);
    else if (x < 0 || y < 0)
      answer = -s21_abs(x / y);
    else
      answer = s21_abs(x / y);
    answer = x - answer * y;
    if (s21_fabs(y) == S21_INF) answer = x;

  } else {
    answer = S21_NAN;
  }
  return answer;
}