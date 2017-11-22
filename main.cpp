#include <iostream>
#include <string>
#include "Personnage.h"
//#include "Personnage.cpp"
//#include "Arme.h"
//#include "Arme.cpp"

using namespace std;


int main()
{
  string pseudoUser;
  bool sortiMenu(false), sortiArene(false);
  int choixMenu(1000), deplacementMenu(1000),
  choixArene(1000);
  
  cout << endl << endl;
  
    // Création des personnages
  Personnage persoUser("Epée courte", 10);
  
  cout << "Entré votre pseudo : ";
  cin >> pseudoUser;
  
  do{ //DEBUT BOUCLE MENU
    
  cout << endl << " -- MENU --" << endl;
  cout << "1: Arène" << endl;
  cout << "2: Personnage" << endl;
  cout << "0: Quitter" << endl;
  cin >> choixMenu;
  
  switch(choixMenu)
  {
    case 0: {
      sortiMenu = true;
      break;
    }
    case 1: {
      deplacementMenu = 1;
      break;
    }
    case 2: {
      cout << endl << pseudoUser + " :" << endl << endl;
      persoUser.afficherEtat();
      cout << endl<< "Retour au menu ..." << endl << endl;
      sortiMenu = false;
      deplacementMenu = 0;
      break;
    }
  }
  
  //Arène
    sortiArene = true;
  do{ //DEBUT BOUCLE ARENE
    
  if(deplacementMenu == 1)
  {
    cout << endl << " -- ARENE -- " << endl;
    cout << "1: Combat" << endl;
    cout << "0: Quitter" << endl;
    cin >> choixArene;
    
    switch (choixArene)
    {
      case 0: {
        cout << endl << endl;
        cout << endl<< "Retour au menu ..." << endl << endl;
        sortiMenu = false;
        sortiArene = true;
        break;
      }
      case 1: {
        // Au combat !
        
        cout << endl << "Retour a l'Arène ..." << endl << endl;
        sortiArene = false;
        sortiMenu = false;
        break;
      }
    }
  }
  }while(!sortiArene); //FIN BOUCLE ARENE
    
  }while(!sortiMenu); //FIN BOUCLE MENU
  
  cout << endl << endl;
  return 0;
}

//alias "comp"="g++ Arme.cpp Personnage.cpp main.cpp && ./a.out"
