#include "cellule.hpp"

Cellule::Cellule(int valeur)
{
    this->valeur = valeur;
}

Cellule::Cellule(int valeur, std::vector<Cellule *> adresses)
{
    this->valeur = valeur;
    this->adresses = adresses;
}