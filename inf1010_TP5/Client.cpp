#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>
#include <numeric>

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

Client::~Client()
{
	delete panier_;
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
	return accumulate(panier_->obtenirConteneur().begin(), panier_->obtenirConteneur().end(),0.0,
		[](double total,pair<int,Produit*> b)
			{
				return total + b.second->obtenirPrix();
			}
	);
}

void Client::afficherPanier() const
{
	// TODO : � modifier
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	panier_->afficher();
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
    codeClient_ = codeClient;
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
	panier_->reinitialiserClient();
}

Produit* Client::trouverProduitPlusCher() const
{
	return panier_->trouverProduitPlusCher();
}
