/*
 * Candidat.cpp
 *
 *  Created on: 2020-11-24
 *      Author: etudiant
 */

#include "Candidat.h"
#include "ContratException.h"
#include "Personne.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using namespace util;

namespace elections
{
	Candidat::Candidat(string p_nas, string p_prenom, string p_nom, Date p_dateNaissance, Adresse p_adresse, int p_partiPolitique):
			Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(p_partiPolitique)
		{
			PRECONDITION(p_partiPolitique >= 0);
			PRECONDITION(p_partiPolitique < PartisPolitiques.size());
		}

	//Candidat::~Candidat() {};

	Candidat* Candidat::clone() const
	{
		return new Candidat(*this); //Appel du constructeur copie
	}



	string Candidat::reqPartiPolitique() const
	{
		return PartisPolitiques[m_partiPolitique];
	}

	string Candidat::reqPersonneFormate() const
	{
		ostringstream os;
		os << "Candidat" <<
		"\n----------------------------------------------"
		<< Personne::reqPersonneFormate()
		<< "\nParti Politique   : " << m_partiPolitique << endl;
		return os.str();
	}

    void Candidat::verifieInvariant() const
    {
    	ASSERTION(m_partiPolitique >= 0);
    	ASSERTION(m_partiPolitique < PartisPolitiques.size());
    }
}
