#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
	 panier_ = new GestionnaireProduits();
}

Client::Client(const string &nom, const string &prenom, int reference,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, reference, codePostal),
      codeClient_(codeClient)
{
	 panier_ = new GestionnaireProduits();
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

GestionnaireProduits* Client::obtenirPanier() const
{
	// TODO : � modifier
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	// TODO : � modifier
    double montant = 0;
    for (const auto pairProduit: panier_->obtenirConteneur())
        montant += pairProduit.second->obtenirPrix();
    return montant;
}

void Client::afficherPanier() const
{
	// TODO : � modifier
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	for (const auto pairProduit : panier_->obtenirConteneur())
		pairProduit.second->afficher();
    cout << endl;
}

void Client::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
    cout << "\t\tcode client:\t" << codeClient_ << endl
         << "\t\tpanier:\t\t" << panier_->obtenirConteneur().size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	// TODO : � modifier
	panier_->supprimer(produit);
}

void Client::ajouterProduit(Produit *produit)
{
	// TODO : � modifier
	panier_->ajouter(produit);
}

void Client::reinitialiser()
{
	// TODO : � modifier
	for (const auto pairProduit : panier_->obtenirConteneur())
	{
        ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(pairProduit.second);
        if (produit) {
            produit->modifierEncherisseur(nullptr);
            produit->modifierPrix(produit->obtenirPrixInitial());
        }
    }
    panier_->obtenirConteneur().clear();
}
