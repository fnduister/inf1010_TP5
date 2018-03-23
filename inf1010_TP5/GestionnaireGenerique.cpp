#include "GestionnaireGenerique.h"


//template <typename T, typename C, typename S, typename A>
//GestionnaireGenerique<T, C, S, A>::GestionnaireGenerique()
//{
//}

template <typename T, typename C, typename S, typename A>
void GestionnaireGenerique<T, C, S, A>::ajouter(T* donnee)
{
	A ajouterFoncteur(conteneur_);
	ajouterFoncteur(donnee);
}

