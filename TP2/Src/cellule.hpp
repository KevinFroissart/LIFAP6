#ifndef LIFAP6_LISTE_CELLULE_HPP
#define LIFAP6_LISTE_CELLULE_HPP
#include <vector>

class Cellule
{

public:
  Cellule(int valeur, std::vector<Cellule *> adresses);
  Cellule(int valeur);
  int valeur;
  std::vector<Cellule *> adresses;

private:
};

#endif
