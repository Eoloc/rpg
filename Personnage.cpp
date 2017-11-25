#include "Personnage.h"

using namespace std;

Personnage::Personnage(string nom) :
m_nom(nom), m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string nom, int vie, int mana, string nomArme, int degatsArme) :
m_nom(nom), m_vie(vie), m_mana(mana),
m_arme(nomArme, degatsArme)
{

}

Personnage::~Personnage()
{

}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
  cible.recevoirDegats(m_arme.getDegats());
  cout << m_nom + " fait " << m_arme.getDegats();
  cout << " dégats à " << cible.m_nom << endl << endl;
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;
  cout << m_nom + " boit une potion et récupère ";
  
  
    if (m_vie > 100)
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    if (m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Personnage::afficherEtat() const
{
    cout << m_nom + " :" << endl << endl;
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}
