#include "liste.hpp"

#include <iostream>
#include <cassert>
#include <string>
#include <random>
#include <ctime>

bool Liste::PileOuFace()
{
  std::srand(std::time(nullptr));
  int x = std::rand() % 2;
  return x == 1 ? true : false;
}

Liste::Liste()
{
  taille_liste = 0;
  courrante = nullptr;
  niveauMax = 0;
  niveauCourrant = 0;
  bidon = new Cellule(NULL);
}

Liste::Liste(const Liste &autre)
{
}

Liste &Liste::operator=(const Liste &autre)
{
}

Liste::~Liste()
{
}

void Liste::ajouter(int valeur)
{
  courrante = bidon;
  niveauCourrant = niveauMax;
  bool found = false;
  bool doublon = false;
  while (!found)
  {
    if (courrante->valeur == valeur)
    {
      found = true;
      doublon = true;
      break;
    }
    else if (courrante->adresses[niveauCourrant] == nullptr || courrante->adresses[niveauCourrant]->valeur > valeur)
    {
      if (niveauCourrant == 0)
      {
        found = true;
        break;
      }
      else
        niveauCourrant--;
    }
    else
      courrante = courrante->adresses[niveauCourrant];
  }

  if (!doublon)
  {

    std::vector<Cellule *> suivant; //on créer une liste d'adresse
    int niveau = 0;
    do
    {
      if (niveau < courrante->adresses.size())
      {
        suivant.push_back(courrante->adresses[niveau]); //on fait pointer les niveau de suivant sur ce que pointait tmp
      }
      else
      {
        suivant.push_back(nullptr); //pour chaque niveau on ajoute un pointeur null
      }
      niveau++;
    } while (PileOuFace()); //on calcul le niveau de la cellule

    Cellule *nouvelleCellule = new Cellule(valeur, suivant); //on créer une nouvelle cellule qui devient la cellule courrante
    for (int i = 0; i < courrante->adresses.size() && i < suivant.size(); i++)
    {
      courrante->adresses[i] = nouvelleCellule; //ici on fait pointer les niveaux de courrante vers la nouvelle cellule
    }
    if (niveau > niveauMax)
    {
      for (int i = niveauMax; i < niveau; i++) //si le niveau de la cellule est plus grand que le niveauMax on pointe les nouveaux niveau sur la cellule
      {
        bidon->adresses.push_back(nouvelleCellule);
      }
      niveauMax = niveau; //Maj du niveauMax
    }
    taille_liste++;
  }
}

void Liste::supprimer(int valeur)
{
  taille_liste--;
}

Cellule *Liste::tete()
{
  return bidon;
}

int Liste::taille() const
{
  return taille_liste;
}

Cellule *Liste::recherche(int valeur)
{
  courrante = bidon;
  niveauCourrant = niveauMax;

  while (true)
  {
    if (courrante->valeur == valeur)
      return courrante;
    else if (niveauCourrant == 0 && courrante->adresses[niveauCourrant]->valeur > valeur)
      return nullptr;
    else if (courrante->adresses[niveauCourrant] == nullptr || courrante->adresses[niveauCourrant]->valeur > valeur)
    {
      if (niveauCourrant == 0)
        return nullptr;
      else
        niveauCourrant--;
    }
    else
      courrante = courrante->adresses[niveauCourrant];
  }
  return nullptr;
}

void Liste::afficher() const
{
}
