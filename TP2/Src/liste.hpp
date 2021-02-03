#ifndef LIFAP6_LISTE_LISTE_HPP
#define LIFAP6_LISTE_LISTE_HPP

#include "cellule.hpp"

class Liste
{

public:
  bool PileOuFace();

  /* construction d'une liste vide */
  Liste();

  /* construction par copie */
  Liste(const Liste &autre);

  /* affectation */
  Liste &operator=(const Liste &autre);

  /* destruction */
  ~Liste();

  /* ajout en tete */
  void ajouter(int valeur);

  /* suppression en tete */
  void supprimer(int valeur);

  /* consultation de la tete */
  Cellule *tete();

  /* taille de la liste */
  int taille() const;

  /* recherche dans la liste */
  Cellule *recherche(int valeur);

  /* affichage */
  void afficher() const;

private:
  int taille_liste;
  Cellule *courrante;
  Cellule *bidon;
  int niveauCourrant;
  int niveauMax;
};

#endif
