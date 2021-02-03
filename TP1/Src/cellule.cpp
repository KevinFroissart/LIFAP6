#include "cellule.hpp"

Cellule::Cellule(int valeur)
{
    this->valeur = valeur;
    this->suivant = nullptr;
}

Cellule::Cellule(int valeur, Cellule *suivant)
{
    this->valeur = valeur;
    this->suivant = suivant;
}