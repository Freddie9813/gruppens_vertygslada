
#include <stdio.h>

void skriv_fizzbuzz(int fran, int till)
{
    for (int tal = fran; tal <= till; tal++) {
        if (tal % 3 == 0 && tal % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (tal % 3 == 0) {
            printf("Fizz\n");
        } else if (tal % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", tal);
        }
    }

}
