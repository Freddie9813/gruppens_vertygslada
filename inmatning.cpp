#include "inmatning.h"
#include <iostream>

bool kontrolleraInmatning()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Felaktig inmatning!\n";
        return false;
    }

    return true;
}