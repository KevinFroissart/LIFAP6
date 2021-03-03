#include <vector>

class cell
{
public:
    int val;
    std::vector<cell *> next;

    cell(); // cellule bidon
    cell(int v);
    ~cell();
};