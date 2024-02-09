#include "./../s21_math.h"

long double s21_ceil(double x) {
  long double result = s21_floor(x) + 1;
  if (result - 1 == x) {
    result--;
  }
  return result;
}