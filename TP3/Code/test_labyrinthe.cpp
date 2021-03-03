#include "labyrinthe.hpp"
#include "UnionFind.hpp"

int main()
{
  Labyrinthe lab(40, 20);
  std::cout << lab << std::endl;

  // lab.abattre_tous_les_murs();
  // std::cout << lab << std::endl;

  // lab.monter_tous_les_murs();
  // std::cout << lab << std::endl;

  // lab.abattre_mur(0, 0, 0, 1);
  // lab.abattre_mur(0, 1, 1, 1);
  // std::cout << lab << std::endl;

  // lab.monter_mur(0, 0, 0, 1);
  // std::cout << lab << std::endl;

  /*UnionFind P(10);
  P.fusion(0, 1);
  P.fusion(2, 0);

  P.fusion(4, 3);
  P.fusion(5, 6);
  P.fusion(6, 4);
  P.fusion(3, 6);
  P.fusion(7, 8);

  std::cout << "find(2) = " << P.find(2) << std::endl;
  std::cout << "find(6) = " << P.find(6) << std::endl;
  std::cout << "AVANT" << std::endl;

  P.print();

  P.fusion(6, 2);

  std::cout << "find(2) = " << P.find(2) << std::endl;
  std::cout << "find(6) = " << P.find(6) << std::endl;

  std::cout << "APRES" << std::endl;

  P.print();*/

  return 0;
}
