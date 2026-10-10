
#include <stdio.h>

int main(void) {
    for (int tal = 1; tal <= 100; tal++) {
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

    return 0;
}
