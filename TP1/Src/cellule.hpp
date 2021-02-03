#ifndef LIFAP6_LISTE_CELLULE_HPP
#define LIFAP6_LISTE_CELLULE_HPP

class Cellule
{

public:
  Cellule(int valeur, Cellule *ptr);
  Cellule(int valeur);
  int valeur;
  Cellule *suivant;

private:
};

#endif
