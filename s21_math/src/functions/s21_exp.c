#include "./../s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0;
  long int del = 2;
  long double xPowI = x;

  for (int i = 1; i < 200000; i++) {
    result += xPowI;  // Ни то, ни другое мы не можем изменить, так как нам
                      // нужна точность до 6 знака и только  при i = 30  exp
                      // имеет нужную точность
    xPowI *= x;  // Возможно если брать не дробные числа для примера, то можно
                 // уменьшить i  без потери точности
    //  = (s21_floor( xPowI * roundD) / roundD);
    xPowI /= del;
    del += 1;
  }
  // for(int i = 2; i < 30; i++) { // При больших числах х или большом i
  // происходит переполнение. В данном случае при i = 30 x может быть только
  // меньше 3
  //     result += xPowI;    // Ни то, ни другое мы не можем изменить, так как
  //     нам нужна точность до 6 знака и только  при i = 30  exp имеет нужную
  //     точность xPowI *= x;               // Возможно если брать не дробные
  //     числа для примера, то можно уменьшить i  без потери точности
  //     //  = (s21_floor( xPowI * roundD) / roundD);
  //     xPowI /= del;
  //     del += 1;
  // }

  if (x == S21_INF)
    result = S21_INF;
  else if (x == -S21_INF)
    result = 0;
  else if ((int)x == x) {
    result = 1.0;
    int flag = 0;
    if (x < 0) flag = 1;
    x = s21_fabs(x);
    for (int i = 0; i < (int)x; i++) {
      result *= S21_E;
    }
    if (flag) result = 1 / result;
  }
  return result;
}
