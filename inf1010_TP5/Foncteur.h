/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <map>
#include "Produit.h"
#include <set>
#include "Usager.h"
#include <algorithm>

// TODO : Créer le FoncteurEgal
template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* objet):t_(objet){};

	int operator () (const std::pair<int, Produit*> pairAcomparer) {
		return pairAcomparer.second == t_;
	};

	int operator () (Usager* usager){
		return usager == t_;
	};
private:
	T* t_;
};


// TODO : Créer le FoncteurGenerateurId
class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId(){};
	int operator () (){
		return id_++;
	};
private:
	int id_ = 0;
};


/*
Attributs :
- id_;
Méthodes :
- operator(); Incrémenter id_ à chaque appel
*/

// TODO : Créer le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
Méthodes :
- operator(); Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
*/

// TODO : Créer le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
Méthodes :
- operator(); Vérifie que le Produit associé à la pair passé en paramètre est compris entre les bornes borneInf_ et borneSup_ (retourne un booléen)
*/

// TODO : Créer le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/
class AjouterProduit
{
public:
	AjouterProduit(std::multimap<int, Produit*>& monMultimap) :multimap_(monMultimap) {};
	auto& operator()(Produit* produit){
		multimap_.insert(make_pair(produit->obtenirReference(),produit));
		return multimap_;
	};
private:
	std::multimap<int, Produit*> &multimap_;
};

//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class AjouterUsager
{
public:
	AjouterUsager(set<Usager*>& setIn) :set_(setIn) {};
	void operator()(Usager* usager) const {
		const auto itrInsert = set_.insert(usager);
	};
private:
	set<Usager*> &set_;
};

// TODO : Créer le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/
class SupprimerProduit
{
public:
	SupprimerProduit(std::multimap<int, Produit*> &myMultimap) :multimap_(myMultimap) {};

	auto& operator()(Produit* produit) {
		const auto itrTrouver = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(produit));
		if (itrTrouver != multimap_.end())
		{
			multimap_.erase(itrTrouver);
		}
		return multimap_;
	};
private:
	std::multimap<int, Produit*> &multimap_;
};

class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager*>& objet):set_(objet){};

	auto& operator()(Usager* usager) {
		const auto itrTrouver = find_if(set_.begin(), set_.end(), FoncteurEgal<Usager>(usager));
		if (itrTrouver != set_.end())
		{
			set_.erase(itrTrouver);
		}
		return set_;
	};
private:
	std::set<Usager*> &set_;
};

