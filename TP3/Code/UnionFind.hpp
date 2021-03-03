#include <iostream>
#include <vector>

class UnionFind
{
private:
    std::vector<int> parent;

public:
    UnionFind(int size);
    void fusion(int x, int y);
    int find(int x);
    int findRecursif(int x);
    void print(void);
    bool merge(int c1, int c2);
};