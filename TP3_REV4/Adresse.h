/*
* Adresse.h
*
* Created on 2020-10-05
* Author : François Gauthier-Drouin
*/

#ifndef ADRESSE_H_
#define ADRESSE_H_

#include <string>

namespace util
{
	class Adresse
	//std::ostringstream
	{
		public:

			//Adresse(); //constructeur (initialise seulement les attributs privés)
			Adresse(int p_numeroCivic, std::string p_nomRue, std::string p_ville, std::string p_codePostal, std::string p_province);

			int reqNumeroCivic();
			//void asgNumeroCivic(int p_numeroCivic);

			std::string reqNomRue();
			//void asgNomRue(std::string p_nomRue);

			std::string reqVille();
			//void asgVille(std::string p_ville);

			std::string reqCodePostal();
			//void asgCodePostal(std::string p_codePostal);

			std::string reqProvince();
			//void asgProvince(std::string p_province);

			/*void asgAdresse(int p_numeroCivic,
									std::string p_nomRue,
									std::string p_ville,
									std::string p_codePostal,
									std::string p_province);*/

			bool operator ==(const Adresse& p_adresse) const;

			std::string reqAdresseFormate() const;

		private:

				int m_numeroCivic;
				std::string m_nomRue;
				std::string m_ville;
				std::string m_codePostal;
				std::string m_province;
				void verifieInvariant() const;
	};
} /* namespace std */

#endif /* ADRESSE_H_ */
