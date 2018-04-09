#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{	
	// on a des pertes avec les doubles avec ces operations d'ou le round 
	// afin d'obtenir la comparaison entre deux doubles du test 50
	// double l = 90.0 * ((100 - 30) / 100.0); // retourne 62.99999999999999
	// on est suppose le comparer a 63.0
    return round(prix_ * ((100 - pourcentageRabais_) / 100.0));

}

void ProduitSolde::afficher() const
{
    Produit::afficher();
    cout << "\t\trabais:\t\t" << pourcentageRabais_ << "%" << endl;
}
