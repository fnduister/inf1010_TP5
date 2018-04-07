#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int reference,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, reference, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
    double montant = 0;
    for (const pair<int,Produit*> produitPair : panier_->obtenirConteneur()) {
        montant += produitPair.second->obtenirPrix() < 5 ? 0 : produitPair.second->obtenirPrix() - 5;
    }
    return montant;
}

void ClientPremium::afficher() const
{
    Client::afficher();
    cout << "\t\tjours restants:\t" << joursRestants_ << endl;
}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
