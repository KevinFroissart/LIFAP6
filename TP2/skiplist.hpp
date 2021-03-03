#include "cell.hpp"
#include <iostream>

class skiplist
{
public:
    cell *first;

    skiplist();
    ~skiplist();

    void insert(int v);
    void print(void);
    void printFull(void);
    cell *find(int v);
};