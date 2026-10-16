#include <stdio.h>

int main() {
  float x, y;-20

  printf("Введіть значення x: ");
  scanf("%f", &x);

  if (x < -19) {
          y =  (2 * x * x * x) + (8 * x * x);
            printf("f(x) = %f\n", y);
  } else {
    if(x>-3) {
        if (x <= 0) {
            y = (2 * x * x * x) + (8 * x * x);
              printf("f(x) = %f\n", y);
        } else {
            if (x>= 8) {
                if (x < 23) {
                    y = (-5 * x * x * x) + 10;
                      printf("f(x) = %f\n", y);
                } else {
                    printf("x поза об’єднанням D1 ∪ D2, функція не визначена\n");
                }
            } else {
                printf("x поза об’єднанням D1 ∪ D2, функція не визначена\n");
            }
        }
    } else {
        printf("x поза об’єднанням D1 ∪ D2, функція не визначена\n");
    }

}
return 0;
}
