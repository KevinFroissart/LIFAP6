#include "Unionfind.hpp"
#include <iostream>

UnionFind::UnionFind(int size) : parent(size)
{
    for (int i = 0; i < size; i++)
    {
        parent[i] = i; //initialement chaque élément est son propre parent (ce sont des singletons)
    }
}

int UnionFind::find(int x)
{
    int p = x;
    while (parent[p] != p)
    {
        p = parent[p];
    }
    return p;
}

int UnionFind::findRecursif(int x)
{
    return parent[x] == x ? x : findRecursif(parent[x]);
}

void UnionFind::fusion(int x, int y)
{
    parent[find(x)] = find(y);
}

void UnionFind::print(void)
{
    for (unsigned int i = 0; i < parent.size(); i++)
        std::cout << "parent[" << i << "] == " << parent[i] << std::endl;
}

bool UnionFind::merge(int c1, int c2)
{
    if (parent[find(c1)] == find(c2))
        return false;

    parent[find(c1)] = find(c2);
    return true;
}