#include <iostream>
#include <string>
#include <sstream>
#include "Adresse.h"
#include "Personne.h"
#include "Date.h"
#include "validationFormat.h"

using namespace std;

int main()

{
	int p_numeroCivic;
	string p_nomRue;
	string p_ville;
	string p_codePostal;
	string p_province;

	string p_nas;
	string p_prenom;
	string p_nom;
	int p_partiPolitique;
	util::Date p_dateNaissance;
	long p_jour;
	long p_mois;
	long p_annee;
	util::Adresse p_adresse;

	cout << "----------------------------------------" << endl;
	cout << "Bienvenue a l'outil de gestion des listes électorales" << endl;
	cout << "----------------------------------------" << endl;
	cout << "" << endl;
	cout << "Inscription d'un candidat" << endl;
	cout << "Choisissez un parti" << endl;

	string temp;
	{
		cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;
		getline (cin, temp);
	}
	p_partiPolitique = temp;
	temp.clear();

	bool verification = false;
		while (!verification)
		{
			cout << "Veuillez entrer sa date de naissance" << endl;
			cout << "Le jour [1..31] : ";
			cin >> p_jour;
			cout << "Le mois [1..12] : ";
			cin >> p_mois;
			cout << "L'annee [1970..2037] : ";
			cin >> p_annee;
			if (d.validerDate(p_jour, p_mois, p_annee))
			{
				verification = true;
			}
			else
			{
			cout << "La date de naissance n'est pas valide" << endl;
			}
		}

		cout << "Entrez l'adresse" << endl;

		cout << "Numéro de rue : " << endl;
		std::cin.clear();
		getline (cin, temp);
		p_numeroCivic = std::atoi(temp.c_str());
		temp.clear();

		if (p_numeroCivic <= 0)
		{
			do
			{
				cout << "Le numéro de rue doit être positif" << endl;
				cout << "" << endl;
				cout << "Numéro de rue : " << endl;
				cout << "Numéro de rue : " << endl;
				std::cin.clear();
				getline (cin, temp);
				p_numeroCivic = std::atoi(temp.c_str());
				temp.clear();
			}
			while (p_numeroCivic <= 0);
		}

		cout << "Rue : " << endl;
		getline (cin, temp);
		p_nomRue = temp;
		temp.clear();

		if (p_nomRue.empty())
		{
			do
			{
				cout << "Le nom de la rue ne peut pas être vide" << endl;
				cout << "" << endl;
				cout << "Rue : " << endl;
				getline (cin, temp);
				p_nomRue = temp;
				temp.clear();
			}
			while (p_nomRue.empty());
		}

		cout << "Ville : " << endl;
		getline (cin, temp);
		p_ville = temp;
		temp.clear();

		if (p_ville.empty())
		{
			do
			{
				cout << "Le nom de la ville ne peut pas être vide" << endl;
				cout << "" << endl;
				cout << "Ville : " << endl;
				getline (cin, temp);
				p_ville = temp;
				temp.clear();
			}
			while (p_ville.empty());
		}

		cout << "Code postal : " << endl;
		getline (cin, temp);
		p_codePostal = temp;
		temp.clear();

		if (p_codePostal.empty())
		{
			do
			{
				cout << "Le code postal ne peut pas être vide" << endl;
				cout << "" << endl;
				cout << "Code postal : " << endl;
				getline (cin, temp);
				p_codePostal = temp;
				temp.clear();
			}
			while (p_codePostal.empty());
		}

		cout << "Province : " << endl;
		getline (cin, temp);
		p_province = temp;
		temp.clear();

		if (p_province.empty())
		{
			do
			{
				cout << "La province ne peut pas être vide" << endl;
				cout << "" << endl;
				cout << "Province : " << endl;
				getline (cin, temp);
				p_province = temp;
				temp.clear();
			}
			while (p_province.empty());
		}

		cout << "Entrez le nom : " << endl;
			getline (cin, temp);
			p_nom = temp;
			temp.clear();

			if (p_nom.empty())
			{
				do
				{
					cout << "Le nom est vide" << endl;
					cout << "Entrez le nom : " << endl;
					getline (cin, temp);
					p_nom = temp;
					temp.clear();
				}
				while (p_nom == "");
			}

			cout << "Entrez le prenom : " << endl;
			getline (cin, temp);
			p_prenom = temp;
			temp.clear();

			if (p_prenom.empty())
			{
				do
				{
					cout << "Le prénom est vide" << endl;
					cout << "Entrez le prenom : " << endl;
					getline (cin, temp);
					p_prenom = temp;
					temp.clear();
				}
				while (p_prenom.empty());
			}

	if (!util::validerNas(p_nas))
	{
		do
		{
			cout << "NAS invalide" << endl;
			cout << "Entrez son numéro d'assurance sociale" << endl;
			getline (cin, temp);
			p_nas = temp;
			temp.clear();
		}
		while (!util::validerNas(p_nas));
	}

	util::Date d(p_jour, p_mois, p_annee);

	util::Adresse adressePersonneCourante(p_numeroCivic, p_nomRue, p_ville, p_codePostal, p_province);
	elections::Personne personneCourante(p_nas, p_prenom, p_nom, d, adressePersonneCourante);

	cout << "Personne enregistrée" << endl;
	cout << "------------------------------------------------" << endl;
	cout << personneCourante.reqPersonneFormate() << endl;

	cout << "Saisir la nouvelle adresse" << endl;
	cout << "Entrez l'adresse" << endl;
	cout << "Numéro de rue : " << endl;
	std::cin.clear();
	getline (cin, temp);
	p_numeroCivic = std::atoi(temp.c_str());
	temp.clear();

	if (p_numeroCivic <= 0)
	{
		do
		{
			cout << "Le numéro de rue doit être positif" << endl;
			cout << "" << endl;
			cout << "Numéro de rue : " << endl;
			cout << "Numéro de rue : " << endl;
			std::cin.clear();
			getline (cin, temp);
			p_numeroCivic = std::atoi(temp.c_str());
			temp.clear();
		}
		while (p_numeroCivic <= 0);
	}

	cout << "Rue : " << endl;
	getline (cin, temp);
	p_nomRue = temp;
	temp.clear();

	if (p_nomRue.empty())
	{
		do
		{
			cout << "Le nom de la rue ne peut pas être vide" << endl;
			cout << "" << endl;
			cout << "Rue : " << endl;
			getline (cin, temp);
			p_nomRue = temp;
			temp.clear();
		}
		while (p_nomRue.empty());
	}

	cout << "Ville : " << endl;
	getline (cin, temp);
	p_ville = temp;
	temp.clear();

	if (p_ville.empty())
	{
		do
		{
			cout << "Le nom de la ville ne peut pas être vide" << endl;
			cout << "" << endl;
			cout << "Ville : " << endl;
			getline (cin, temp);
			p_ville = temp;
			temp.clear();
		}
		while (p_ville.empty());
	}

	cout << "Code postal : " << endl;
	getline (cin, temp);
	p_codePostal = temp;
	temp.clear();

	if (p_codePostal.empty())
	{
		do
		{
			cout << "Le code postal ne peut pas être vide" << endl;
			cout << "" << endl;
			cout << "Code postal : " << endl;
			getline (cin, temp);
			p_codePostal = temp;
			temp.clear();
		}
		while (p_codePostal.empty());
	}

	cout << "Province : " << endl;
	getline (cin, temp);
	p_province = temp;
	temp.clear();

	if (p_province.empty())
	{
		do
		{
			cout << "La province ne peut pas être vide" << endl;
			cout << "" << endl;
			cout << "Province : " << endl;
			getline (cin, temp);
			p_province = temp;
			temp.clear();
		}
		while (p_province.empty());
	}

	adressePersonneCourante.asgAdresse(p_numeroCivic, p_nomRue, p_ville, p_codePostal, p_province);
	personneCourante.asgPersonne(p_nas, p_prenom, p_nom, d, adressePersonneCourante);

	cout << "Personne enregistrée" << endl;
	cout << "------------------------------------------------" << endl;
	cout << personneCourante.reqPersonneFormate() << endl;
	cout << "Fin du programme" << endl;

return 0;
}
