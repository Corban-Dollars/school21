#include "./../s21_math.h"

long double s21_acos(double x) {
  long double sinX = s21_sqrt(1 - x * x);
  long double result;
  if (x < -1 || x > 1) {
    result = S21_NAN;
  } else if (x == 0) {
    result = S21_PI / 2;
  } else if (x < 0) {
    result = S21_PI - s21_asin(sinX);
  } else {
    result = s21_asin(sinX);
  }
  return result;
}
