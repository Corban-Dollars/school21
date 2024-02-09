// #include "s21_math.h"
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
//     int negInt = -5;
//     int posInt = 5;
//     int zero = 0;

//     double negD = -5.0;
//     double posD = 5.0;
//     double zeroD = 0.0;

//     int roundD = 1000000;

//     // ABS tests
//     // printf("\n\nABS TESTS:\n");
//     // printf("ABS %d: %d %d %s\n", negInt, s21_abs(negInt), abs(negInt),
//     s21_abs(negInt)==abs(negInt)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("ABS %d: %d %d %s\n", zero, s21_abs(zero), abs(zero),
//     s21_abs(zero)==abs(zero)?"Test passed\033[0m":"Test  \033[0;32m
//     \033[0;31m failed\033[0m");
//     // printf("ABS %d: %d %d %s\n", posInt, s21_abs(posInt), abs(posInt),
//     s21_abs(posInt)==abs(posInt)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // // FABS tests
//     // printf("\n\nFABS TESTS:\n");
//     // printf("FABS %f: %f %f %s\n", negD, s21_fabs(negD), fabs(negD),
//     s21_fabs(negD)==fabs(negD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // printf("FABS %f: %f %f %s\n", zeroD, s21_fabs(zeroD), fabs(zeroD),
//     s21_fabs(zeroD)==fabs(zeroD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("FABS %f: %f %f %s\n", posD, s21_fabs(posD), fabs(posD),
//     s21_fabs(posD)==fabs(posD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // //FLOOR tests
//     // printf("\n\n\nFLOOR TESTS1:\n");
//     // for(double i = negD; i < posD; i += 0.8765432) {
//     //     printf("Floor %f: %Lf %f %s\n", i, s21_floor(i), floor(i),
//     s21_floor(i)==floor(i)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // }
//     // printf("\n\nFLOOR TESTS2:\n");
//     // printf("Floor %f: %Lf %f %s\n", negD, s21_floor(negD), floor(negD),
//     s21_floor(negD)==floor(negD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("Floor %f: %Lf %f %s\n", zeroD, s21_floor(zeroD), floor(zeroD),
//     s21_floor(zeroD)==floor(zeroD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("Floor %f: %Lf %f %s\n", posD, s21_floor(posD), floor(posD),
//     s21_floor(posD)==floor(posD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // // check out these tests
//     // printf("\n\nFLOOR TESTS3:\n");
//     // printf("Floor %f: %Lf %f %s\n", 0.99999999, s21_floor(0.99999999),
//     floor(0.99999999),
//     s21_floor(0.99999999)==floor(0.99999999)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");//???????
//     // printf("Floor %f: %Lf %f %s\n", 0.999999, s21_floor(0.999999),
//     floor(0.999999), s21_floor(0.999999)==floor(0.999999)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("Floor %f: %Lf %f %s\n", 0.99999901, s21_floor(0.99999901),
//     floor(0.99999901),
//     s21_floor(0.99999901)==floor(0.99999901)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // printf("\n\n\nSIN TESTS:\n");
//     // for(double i = negD * 50; i < posD * 50; i += 4.12345678) {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("Sin %f : %Lf %Lf %s\n", i, (s21_floor(s21_sin(i) * roundD)
//     / roundD) , (s21_floor(sin(i) * roundD) / roundD), (s21_floor(s21_sin(i)
//     * roundD) / roundD) == (s21_floor(sin(i) * roundD) / roundD)
//     ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // }
//     // printf("Sin %f : %Lf %f %s\n", zeroD, s21_sin(zeroD), sin(zeroD),
//     s21_sin(zeroD)==sin(zeroD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // printf("\n\n\nCOS TESTS:\n");
//     // for(double i = negD * 50; i < posD * 50; i += 4.12345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("Cos %f : %Lf %Lf %s\n", i, (s21_floor(s21_cos(i) * roundD)
//     / roundD) , (s21_floor(cos(i) * roundD) / roundD), (s21_floor(s21_cos(i)
//     * roundD) / roundD) == (s21_floor(cos(i) * roundD) / roundD)
//     ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // }
//     // printf("Cos %f : %Lf %f %s\n", zeroD, s21_cos(zeroD), cos(zeroD),
//     s21_cos(zeroD)==cos(zeroD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // printf("\n\n\nSQRT TESTS:\n");
//     // for(double i = negD; i < posD; i += 0.8765432) {
//     //     // Я не знаю почему, но без округления через floor при i < 0 тесты
//     не проходят. Только если происходит floor(nan * roundD / roundD)
//     результаты будут равны...
//     //     printf("Sqrt %f : %Lf %f %s\n", i, s21_sqrt(i), sqrt(i),
//     s21_floor(s21_sqrt(i) * roundD) / roundD == s21_floor(sqrt(i) * roundD) /
//     roundD?"\033[0;32mTest passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // }
//     // printf("Sqrt %f : %Lf %f %s\n", zeroD, s21_sqrt(zeroD), sqrt(zeroD),
//     s21_sqrt(zeroD)==sqrt(zeroD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // printf("\n\n\nFMOD TESTS:\n");
//     double de = negD * 50;
//     // for(double i = negD * 50; i < posD * 50; i += 4.12345678)  {

//     //     printf("FMOD %f on %f: %Lf %f %s\n", i, de, s21_fmod(i, de),
//     fmod(i, de), s21_fmod(i, de)==fmod(i, de)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     //     de *= (-0.93);
//     // }
//     // printf("FMOD %f on %f: %Lf %f %s\n", 4.1, 0.0, s21_fmod(4.1, 0.0),
//     fmod(4.1, 0.0), (s21_floor(s21_fmod(4.1, 0.0) * roundD) /
//     roundD)==(s21_floor(fmod(4.1, 0.0) * roundD) / roundD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // printf("\n\n\nTAN TESTS:\n");
//     // for(double i = negD * 50; i < posD * 50; i += 4.12345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("TAN %f : %Lf %Lf %s\n", i, (s21_floor(s21_tan(i) * roundD)
//     / roundD) , (s21_floor(tan(i) * roundD) / roundD), (s21_floor(s21_tan(i)
//     * roundD) / roundD) == (s21_floor(tan(i) * roundD) / roundD)
//     ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // }
//     // double piDivTwo = M_PI / 2;
//     // printf("TAN %f : %Lf %f %s\n", zeroD, s21_tan(zeroD), tan(zeroD),
//     s21_tan(zeroD)==tan(zeroD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // // s21_tan получает inf? а tan очень большое число. В данном случае мы
//     не полем точно отправить PI / 2, поэтому и не можем получить inf. Этот
//     тест невозможен
//     // // printf("TAN %f : %Lf %f %s\n", piDivTwo, s21_tan(piDivTwo),
//     tan(piDivTwo), s21_tan(piDivTwo)==tan(piDivTwo)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // printf("\n\n\nPOW TESTS:\n");
//     // de = 1.01;
//     // for(double i = -10 ; i < 50; i += 0.12345678)  {

//     //     printf("POW %f on %f: %Lf %f %s\n", i, de, s21_pow(i, de), pow(i,
//     de), (s21_floor(s21_pow(i, de) * roundD) / roundD)==(s21_floor(pow(i, de)
//     * roundD) / roundD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     //     de *= (-1.002);
//     // }
//     // printf("POW %f on %f: %Lf %f %s\n", negD, -0.3, s21_pow(negD, -0.3),
//     pow(negD, -0.3), (s21_floor(s21_pow(negD, -0.3) * roundD) /
//     roundD)==(s21_floor(pow(negD, -0.3) * roundD) / roundD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("POW %f on %f: %Lf %f %s\n", 4.1, 0.0, s21_pow(4.1, 0.0),
//     pow(4.1, 0.0), (s21_floor(s21_pow(4.1, 0.0) * roundD) /
//     roundD)==(s21_floor(pow(4.1, 0.0) * roundD) / roundD)?"\033[0;32mTest
//     passed\033[0m":"\033[0;31mTest failed\033[0m");
//     // printf("POW %f on %f: %Lf %f %s\n", 9223372036855807.0,
//     9223372036477507.0, s21_pow(4.1, 0.0), pow(4.1, 0.0),
//     (s21_floor(s21_pow(4.1, 0.0) * roundD) / roundD)==(s21_floor(pow(4.1,
//     0.0) * roundD) / roundD)?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // printf("\n\n\nEXP TESTS:\n");
//     // for(double i = -25; i < 25; i += 0.12345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("EXP %f : %Lf %f %s\n", i, s21_exp(i) , exp(i),
//     (s21_floor(s21_exp(i) * roundD) / roundD) == (s21_floor(exp(i) * roundD)
//     / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // }
//     // printf("EXP %f : %Lf %f %s\n", zeroD, s21_exp(zeroD) , exp(zeroD),
//     (s21_floor(s21_exp(zeroD) * roundD) / roundD) == (s21_floor(exp(zeroD) *
//     roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // printf("\n\n\nLOG TESTS:\n");
//     // for(double i = -1; i < posD *10; i += 0.12345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("LOG %f : %Lf %f %s\n", i, s21_log(i) , log(i),
//     (s21_floor(s21_log(i) * roundD) / roundD) == (s21_floor(log(i) * roundD)
//     / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // }
//     // printf("LOG %f : %Lf %f %s\n", negD, s21_log(negD) , log(negD),
//     (s21_floor(s21_log(negD) * roundD) / roundD) == (s21_floor(log(negD) *
//     roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // printf("LOG %f : %Lf %f %s\n", zeroD, s21_log(zeroD) , log(zeroD),
//     (s21_floor(s21_log(zeroD) * roundD) / roundD) == (s21_floor(log(zeroD) *
//     roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // printf("\n\n\nACOS TESTS:\n");
//     // for(double i = negD / 4; i < posD / 4; i += 0.12345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     if(i > -0.2 && i < 0.2) continue;
//     //     printf("ACOS %f : %Lf %f %s\n", i, s21_acos(i) , acos(i),
//     (s21_floor(s21_acos(i) * roundD) / roundD) == (s21_floor(acos(i) *
//     roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // }
//     // printf("ACOS %f : %Lf %f %s\n", zeroD, s21_acos(zeroD) , acos(zeroD),
//     (s21_floor(s21_acos(zeroD) * roundD) / roundD) == (s21_floor(acos(zeroD)
//     * roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     // printf("\n\n\nASIN TESTS:\n");
//     // for(double i = negD / 4; i < posD / 4; i += 0.12345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("ASIN %f : %Lf %f %s\n", i, s21_asin(i) , asin(i),
//     (s21_floor(s21_asin(i) * roundD) / roundD) == (s21_floor(asin(i) *
//     roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // }
//     // printf("ASIN %f : %Lf %f %s\n", zeroD, s21_asin(zeroD) , asin(zeroD),
//     (s21_floor(s21_asin(zeroD) * roundD) / roundD) == (s21_floor(asin(zeroD)
//     * roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     printf("\n\n\nATAN TESTS:\n");
//     for(double i = -5 ; i < 5 ; i += 0.112345678)  {
//         //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//         знака после запятой printf("ATAN %f : %Lf %f %s\n", i, s21_atan(i) ,
//         atan(i), (s21_floor(s21_atan(i) * roundD) / roundD) ==
//         (s21_floor(atan(i) * roundD) / roundD) ?"\033[0;32mTest
//         passed\033[0m":"\033[0;31mTest failed\033[0m");
//     }
//     printf("ATAN %f : %Lf %f %s\n", zeroD, s21_atan(zeroD) , atan(zeroD),
//     (s21_floor(s21_atan(zeroD) * roundD) / roundD) == (s21_floor(atan(zeroD)
//     * roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//         printf("ATAN %f : %Lf %f %s\n", 1.001, s21_atan(1.001) , atan(1.001),
//         (s21_floor(s21_atan(1.001) * roundD) / roundD) ==
//         (s21_floor(atan(1.001) * roundD) / roundD) ?"\033[0;32mTest
//         passed\033[0m":"\033[0;31mTest failed\033[0m");

//     // printf("\n\n\nCEIL TESTS:\n");
//     // for(double i = negD ; i < posD ; i += 0.312345678)  {
//     //     //(s21_floor(s21_sin(i) * roundD) / roundD)  Это округление до  6
//     знака после запятой
//     //     printf("CEIL %f : %Lf %f %s\n", i, s21_ceil(i) , ceil(i),
//     (s21_floor(s21_ceil(i) * roundD) / roundD) == (s21_floor(ceil(i) *
//     roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");
//     // }
//     // printf("CEIL %f : %Lf %f %s\n", zeroD, s21_ceil(zeroD) , ceil(zeroD),
//     (s21_floor(s21_ceil(zeroD) * roundD) / roundD) == (s21_floor(ceil(zeroD)
//     * roundD) / roundD) ?"\033[0;32mTest passed\033[0m":"\033[0;31mTest
//     failed\033[0m");

//     return 0;
// }