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
	// TODO : À modifier
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	// TODO : À modifier
	return accumulate(panier_->obtenirConteneur().begin(), panier_->obtenirConteneur().end(),0.0,
		[](double total,pair<int,Produit*> b)
			{
				return total + b.second->obtenirPrix();
			}
	);
}

void Client::afficherPanier() const
{
	// TODO : À modifier
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	for (const auto pairProduit : panier_->obtenirConteneur())
		pairProduit.second->afficher();
    cout << endl;
}

void Client::afficher() const
{
	// TODO : À modifier
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
	// TODO : À modifier
	panier_->supprimer(produit);
}

void Client::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
	panier_->ajouter(produit);
}

void Client::reinitialiser()
{
	// TODO : À modifier
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

Produit* Client::trouverProduitPlusCher() const
{
	return panier_->trouverProduitPlusCher();
}
