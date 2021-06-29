/*On s’attend à pouvoir disposer d’un constructeur avec paramètres, des accesseurs pour chaque attribut, un mutateur pour pouvoir modifier une adresse existante dans son ensemble, d’un opérateur d’égalité basé sur l’ensemble des attributs et d’une méthode permettant de disposer des informations relatives à une adresse sous la forme d’un objet string et sous le format suivant :
235, rue de l'Université, Québec, G1V 0A7, QC
Utilisez la classe ostringstream du standard pour formater les informations sur l’adresse.
Le numéro civique doit être positif, les autres attributs seront non vides.
Remarque: Cette classe appartient à l'espace de nom util.*/

//implanter théorie du contrat

#include "Adresse.h"
#include <sstream>
#include <string>
#include <iostream>
#include "ContratException.h"
#include <iomanip> //À GARDER?
#include <regex> //À GARDER?

using namespace std;

namespace util
{
	//Définition du constructeur
	//Adresse::Adresse(){};

	Adresse::Adresse(int p_numeroCivic, string p_nomRue, string p_ville, string p_codePostal, string p_province): m_numeroCivic(p_numeroCivic), m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal), m_province(p_province)
	{
		PRECONDITION(p_numeroCivic >= 0);
		PRECONDITION(!p_nomRue.empty());
		PRECONDITION(!p_ville.empty());
		PRECONDITION(!p_codePostal.empty());
		PRECONDITION(!p_province.empty());

		POSTCONDITION(reqNumeroCivic() == p_numeroCivic);
		POSTCONDITION(reqNomRue() == p_nomRue);
		POSTCONDITION(reqVille() == p_ville);
		POSTCONDITION(reqCodePostal() == p_codePostal);
		POSTCONDITION(reqProvince() == p_province);

		INVARIANTS();
	}

	//Définition des accesseurs et mutateurs par attribut individuel
	int Adresse::reqNumeroCivic()
	{
		return m_numeroCivic;
	}

	/*void Adresse::asgNumeroCivic(int p_numeroCivic)
	{
		m_numeroCivic = p_numeroCivic;
	}*/

	string Adresse::reqNomRue()
	{
		return m_nomRue;
	}

	/*void Adresse::asgNomRue(string p_nomRue)
	{
		m_nomRue = p_nomRue;
	}*/

	string Adresse::reqVille()
	{
		return m_ville;
	}

	/*void Adresse::asgVille(string p_ville)
	{
		m_ville = p_ville;
	}*/

	string Adresse::reqCodePostal()
	{
		return m_codePostal;
	}

	/*void Adresse::asgCodePostal(string p_codePostal)
	{
		m_codePostal = p_codePostal;
	}*/

	string Adresse::reqProvince()
	{
		return m_province;
	}

	/*void Adresse::asgProvince(std::string p_province)
	{
		m_province = p_province;
	}*/
	//Mutateur général pour tous les attributs
	/*void Adresse::asgAdresse(int p_numeroCivic,
							string p_nomRue,
							string p_ville,
							string p_codePostal,
							string p_province)
	{
		asgNumeroCivic(p_numeroCivic);
		asgNomRue(p_nomRue);
		asgVille(p_ville);
		asgCodePostal(p_codePostal);
		asgProvince(p_province);
	}*/
    //Opérateur d'égalité
    bool Adresse::operator ==(const Adresse& p_adresse) const
    {
        return m_numeroCivic == p_adresse.m_numeroCivic &&
            m_nomRue == p_adresse.m_nomRue &&
            m_ville == p_adresse.m_ville &&
            m_codePostal == p_adresse.m_codePostal &&
            m_province == p_adresse.m_province;
                
    }

    //Méthode permettant d'afficher tous les éléments d'une adresse sur une seule ligne

    string Adresse::reqAdresseFormate() const
    {
    	ostringstream os;
		os << m_numeroCivic << ", "
		<< m_nomRue         << ", "
		<< m_ville          << ", "
		<< m_codePostal     << ", "
		<< m_province;
		return os.str();
    }
}
