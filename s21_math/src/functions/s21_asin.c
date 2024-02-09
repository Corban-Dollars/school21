#include "./../s21_math.h"

long double s21_asin(double x) {
  // long double result = 0;
  // long double up = x;
  // long int helpTmp = 1;

  double sum = x;
  double term = x;
  int n = 1;

  // double term = x;
  // double x_sq = x * x;
  // long long int factor = 1;
  // long long int double_fact = 1;
  if (x < -1 || x > 1) {
    sum = S21_NAN;
  } else if (x == 1) {
    sum = S21_PI / 2;
  } else if (x == -1) {
    sum = -S21_PI / 2;
  } else {
    for (int i = 1; i < 200; i++) {
      //     result += fact(2 * i) * up / (fact(i) * fact(i) * (2 * i + 1)); //
      //     Стандартная формула? которая вообще не работает up *= x*x; helpTmp
      //     *= 4;
      term *= (x * x * (2 * i - 1) * (2 * i - 1)) / (2 * i * (2 * i + 1));
      sum += term;
      n++;
      // factor *= (2 * i - 1 ) * (2 * i); // почти польностью не работает
      // double_fact *= (2 * i - 1);
      // term = term * x_sq * ( 2 * i - 1) * (2 * i - 1) / (2 * i - 1) / ((2 *
      // i) * (2 * i + 1)); sum += term * double_fact * double_fact / factor;
    }
  }
  return sum;
}
