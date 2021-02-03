#include "liste.hpp"

#include <iostream>
#include <cassert>
#include <string>

Liste::Liste()
{
  taille_liste = 0;
  first = nullptr;
  last = first;
}

Liste::Liste(const Liste &autre)
{
  taille_liste = 0;
  first = nullptr;
  Cellule *tmp = autre.first;
  while (tmp->suivant != nullptr)
  {
    ajouter_en_tete(tmp->valeur);
    tmp = tmp->suivant;
  }
  ajouter_en_queue(tmp->valeur);
}

Liste &Liste::operator=(const Liste &autre)
{
  taille_liste = 0;
  first = nullptr;
  Cellule *tmp = autre.first;
  while (tmp->suivant != nullptr)
  {
    ajouter_en_tete(tmp->valeur);
    tmp = tmp->suivant;
  }
  ajouter_en_queue(tmp->valeur);
  return *this;
}

Liste::~Liste()
{
  while (first->suivant != nullptr)
  {
    supprimer_en_tete();
  }
  delete last;
}

void Liste::ajouter_en_tete(int valeur)
{
  first = new Cellule(valeur, first);
  if (taille_liste == 0)
    last = first;
  taille_liste++;
}

void Liste::ajouter_en_queue(int valeur)
{
  if (taille_liste == 0)
  {
    last = new Cellule(valeur, nullptr);
    first = last;
  }
  else
  {
    last->suivant = new Cellule(valeur, nullptr);
    last = last->suivant;
  }
  taille_liste++;
}

void Liste::supprimer_en_tete()
{
  if (first)
  {
    Cellule *tmp = first;
    first = tmp->suivant;
    tmp->suivant = nullptr;
    taille_liste--;
    delete tmp;
  }
}

Cellule *Liste::tete()
{
  return first;
}

const Cellule *Liste::tete() const
{
  return first;
}

Cellule *Liste::queue()
{
  return last;
}

const Cellule *Liste::queue() const
{
  return last;
}

int Liste::taille() const
{
  return taille_liste;
}

Cellule *Liste::recherche(int valeur)
{
  Cellule *tmp = first;
  for (int i = 0; i < taille_liste; i++)
  {
    if (tmp->valeur == valeur)
      return tmp;
    tmp = tmp->suivant;
  }
  return nullptr;
}

const Cellule *Liste::recherche(int valeur) const
{
  Cellule *tmp = first;
  for (int i = 0; i < taille_liste; i++)
  {
    if (tmp->valeur == valeur)
      return tmp;
    tmp = tmp->suivant;
  }
  return nullptr;
}

void Liste::afficher() const
{
  std::string affichage = "";
  Cellule *tmp = first;
  affichage += "[ ";
  for (int i = 0; i < taille_liste; i++)
  {
    affichage += std::to_string(tmp->valeur) + " ";
    tmp = tmp->suivant;
  }
  affichage += "]";
  std::cout << affichage << std::endl;
}
