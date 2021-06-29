
#include "Personne.h"
#include "ContratException.h"
#include "validationFormat.h"
#include "Adresse.h"
#include "Date.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip> //À GARDER?
#include <regex> //À GARDER?


//à modifier si nécessaire pour implanter la théorie du contrat

using namespace std;
using namespace util;

namespace elections
{
	//Définition du constructeur
	Personne::Personne(string p_nas, string p_prenom, string p_nom, util::Date p_dateNaissance, util::Adresse p_adresse):m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(p_dateNaissance), m_adresse(p_adresse)
	{
		PRECONDITION(validerNas(p_nas));
		PRECONDITION(!p_prenom.empty());
		PRECONDITION(!p_nom.empty());

		POSTCONDITION(reqNas() == p_nas);
		POSTCONDITION(reqPrenom() == p_prenom);
		POSTCONDITION(reqNom() == p_nom);

		INVARIANTS();
	}


	//Définition des accesseurs et mutateurs par attribut individuel
	string Personne::reqNas() const
	{
		ASSERTION(validerNas(m_nas));
		return m_nas;
	}

	string Personne::reqPrenom() const
	{
		ASSERTION(!m_prenom.empty());
		return m_prenom;
	}

	string Personne::reqNom() const
	{
		ASSERTION(!m_nom.empty());
		return m_nom;
	}

	util::Date Personne::reqDateNaissance() const
	{
		ASSERTION(!m_dateNaissance.reqDateFormatee().empty());
		return m_dateNaissance;
	}

	util::Adresse Personne::reqAdresse() const
	{
		ASSERTION(!m_adresse.reqAdresseFormate().empty());
		return m_adresse;
	}

	void Personne::asgAdresse(const Adresse& p_adresse)
	{
		m_adresse = p_adresse;
	}

    //Méthode permettant d'afficher tous les éléments d'un objet Personne

    virtual string Personne::reqPersonneFormate() const
    {
    		ostringstream os;
            os << "NAS              : " << m_nas <<
            "\nPrenom            : " << m_prenom <<
            "\nNom               : " << m_nom <<
            "\nDate de naissance : " << m_dateNaissance.reqDateFormatee() <<
            "\nAdresse           : " << m_adresse.reqAdresseFormate();
            return os.str();
    }

    void Personne::verifieInvariant() const
    {
		ASSERTION(reqNas() == m_nas);
		ASSERTION(reqPrenom() == m_prenom);
		ASSERTION(reqNom() == m_nom);
    }
}
