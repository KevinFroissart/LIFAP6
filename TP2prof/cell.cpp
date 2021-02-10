#include "cell.hpp"
#include <stdlib.h>

cell::cell(int v)
{
    int h = 1;
    while (rand() % 2)
        ++h;
    next.resize(h);
    for (int i = 0; i < h; i++)
        this->next[i] = nullptr;
    this->val = v;
}

cell::cell()
{
}

cell::~cell()
{
    if (next[0] != nullptr)
        delete next[0];
}