#include "./../s21_math.h"

long double s21_log(double x) {  // Приведем к виду, необходимому для разложения
                                 // ln(1 - x) -> x = 1 - (1 - x)
  long double d = x;
  long double result = 0.0;
  long double term = (d - 1);
  long long del = 2;
  long double temp = term;
  int one = -1;

  if (x == 0.0)
    result = -S21_INF;
  else if (x < 0)
    result = S21_NAN;
  else if (x == S21_INF)
    result = S21_INF;
  else {
    if (x > 1) {
      term /= d;
      temp /= d;
      for (int i = 0; i < 200000; i++) {
        result += temp;
        term *= (d - 1) / d;
        temp = term;
        temp /= del;
        del += 1;
      }

    } else {
      for (int i = 0; i < 200000; i++) {
        result = temp > S21_EPS ? result - temp : result + temp;
        term *= (d - 1);
        temp = term * one;
        temp /= del;
        del += 1;
        one *= -1;
      }
    }

    // for(int i = 1; i < 30; i++) { // При больших числах или большом i
    // происходит переполнение. В данном случае еще хуже чем в exp
    //     result -= term / i;
    //     term *= (1 - x);
    //     // term = (s21_floor( term * roundD) / roundD);
    // }
  }
  return result;
}