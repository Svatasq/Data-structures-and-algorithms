#include <stdio.h>

int main() {
  float x, y;

  printf("Введіть значення x: ");
  scanf("%f", &x);

  if ((x < -19) || (x > -3 && x <= 0)) {
        y =  (2 * x * x * x) + (8 * x * x);
        printf("f(x) = %f\n", y);
  } else {
    if (x >=8 && x < 23) {
        y = (-5 * x * x * x) + 10;
        printf("f(x) = %f\n", y);
  } else {
    printf("x поза об’єднанням D1 ∪ D2, функція не визначена\n");
  }
  } 
 return 0;
}
