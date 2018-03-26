#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
	catalogue_ = new GestionnaireProduits();
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	catalogue_ = new GestionnaireProduits();
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : � modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	for (const pair<int, Produit*> pairProduit : catalogue_->obtenirConteneur())
		pairProduit.second->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO : � modifier
	for (const pair<int, Produit*> pairProduit : catalogue_->obtenirConteneur())
		pairProduit.second->modifierFournisseur(nullptr);
    catalogue_->obtenirConteneur().clear();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : � modifier

    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : � modifier
    produit->modifierFournisseur(nullptr);
	catalogue_->supprimer(produit);
}

Produit* Fournisseur::trouverProduitPlusCher() const
{
	return catalogue_->trouverProduitPlusCher();
}
