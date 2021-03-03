#include <iostream>
#include "skiplist.hpp"
#include <stdlib.h>
#include <random>
#include <time.h>

int main(void)
{
    std::cout << "Début du test" << std::endl;
    srand(time(NULL));
    skiplist sl;
    for (int i = 0; i < 10; i++)
    {
        sl.insert(rand() % 100);
    }

    sl.printFull();

    std::cout << std::endl;
    std::cout << "Fin du test" << std::endl;
    return 0;
}