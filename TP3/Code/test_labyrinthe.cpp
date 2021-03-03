#include "labyrinthe.hpp"

int main()
{
  Labyrinthe lab(40, 20) ;
  std::cout << lab << std::endl ;

  lab.abattre_tous_les_murs() ;
  std::cout << lab << std::endl ;

  lab.monter_tous_les_murs() ;
  std::cout << lab << std::endl ;

  lab.abattre_mur(0,0,0,1) ;
  lab.abattre_mur(0,1,1,1) ;
  std::cout << lab << std::endl ;

  lab.monter_mur(0,0,0,1) ;
  std::cout << lab << std::endl ;

  return 0 ;
}
