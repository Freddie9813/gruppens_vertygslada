#include <iostream>
#include <stdio.h>

void skriv_fizzbuzz(int fran, int till)
{
    for (int i = fran; i <= till; i++)
    {
        if (i % 15 == 0)
        {
            std::cout << "FizzBuzz\n";
        }
        else if (i % 3 == 0)
        {
            std::cout << "Fizz\n";
        }
        else if (i % 5 == 0)
        {
            std::cout << "Buzz\n";
        }
        else
        {
            std::cout << i << " \n";
        }
    }
}

void fizzbuzz_sammanfattning(int fran, int till, char *sammanfattning)
{
    int antal_fizz = 0;
    int antal_buzz = 0;
    int antal_fizzbuzz = 0;

    for (int tal = fran; tal <= till; tal++)
    {
        if (tal % 3 == 0 && tal % 5 == 0)
        {
            antal_fizzbuzz++;
        }
        else if (tal % 3 == 0)
        {
            antal_fizz++;
        }
        else if (tal % 5 == 0)
        {
            antal_buzz++;
        }
    }

    sprintf(sammanfattning, "Fizz: %d, Buzz: %d, FizzBuzz: %d",
            antal_fizz, antal_buzz, antal_fizzbuzz);
}
