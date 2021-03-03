#include "skiplist.hpp"
#include <stdlib.h>

skiplist::skiplist()
{
    first = new cell();
}

skiplist::~skiplist()
{
    delete first;
}

void skiplist::insert(int v)
{

    if (find(v) != nullptr)
        return;

    cell *c = first;
    int level = first->next.size() - 1;

    cell *tmp = new cell(v);
    int h = (int)tmp->next.size();

    if (h > (int)first->next.size())
    {
        first->next.resize(h);
        for (int i = level + 1; i < h; i++)
            first->next[i] = tmp;
    }

    while (level >= 0)
    {
        while ((c->next[level] != nullptr) && (v >= c->next[level]->val))
            c = c->next[level];
        if ((c != first) && (c->val == v))
            return;
        if (level < h)
        {
            tmp->next[level] = c->next[level];
            c->next[level] = tmp;
        }
        level--;
    }
}

cell *skiplist::find(int v)
{
    cell *c = first;
    int level = first->next.size() - 1;

    while (level >= 0)
    {
        while ((c->next[level] != nullptr) && (v <= c->next[level]->val))
            c = c->next[level];
        if ((c != first) && (c->val == v))
            return c;
        level--;
    }
    return nullptr;
}

void skiplist::print(void)
{
    if (first->next.size() == 0)
    {
        std::cout << "[]";
    }
    else
    {
        std::cout << "[ ";
        cell *c = first->next[0];
        while (c != nullptr)
        {
            std::cout << c->val << " ";
            c = c->next[0];
        }
        std::cout << "]";
    }
}

void skiplist::printFull(void)
{
    if (first->next.size() == 0)
    {
        std::cout << "[]";
    }
    else
    {
        printf("[xx]-[%14p]-|", first);
        for (long unsigned int i = 0; i < first->next.size(); i++)
        {
            printf("-[%14p]", first->next[i]);
        }
        cell *c = first->next[0];
        std::cout << std::endl;
        while (c != nullptr)
        {
            printf("[%2d]-[%14p]-|", c->val, c);
            for (long unsigned int i = 0; i < c->next.size(); i++)
            {
                printf("-[%14p]", c->next[i]);
            }
            std::cout << std::endl;
            c = c->next[0];
        }
    }
}