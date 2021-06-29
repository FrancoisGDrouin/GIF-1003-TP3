#include <gtest/gtest.h>
#include "Circonscription.h"
#include "ContratException.h"
#include "Date.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Adresse.h"
#include "Personne.h"

using namespace util;
using namespace elections;

TEST(Circonscription, ConstructeurValide)
{
	Adresse Adresse1(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	Date Date1(01,01,2001);
	Candidat Candidat1("640454286", "Joe", "Blo", Date1, Adresse1, 0);
	Circonscription Circonscription1("Saint-Augustin", Candidat1);

	ASSERT_EQ("Saint-Augustin", Circonscription1.reqNomCirconscription());
	//ASSERT_EQ(Candidat1.reqPersonneFormate(), Circonscription1.reqDeputeElu().reqPersonneFormate());
}

TEST(Circonscription, reqNomCirconscriptionValide)
{
	Adresse Adresse1(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	Date Date1(01,01,2001);
	Candidat Candidat1("640454286", "Joe", "Blo", Date1, Adresse1, 0);

	ASSERT_THROW(Circonscription Circonscription1("", Candidat1);,PreconditionException);
}

class circonscriptionTest : public ::testing::Test
{
	public :

	circonscriptionTest(): Circonscription1("Saint-Augustin", Candidat("640454286", "Joe", "Blo", Date(01,01,2001), Adresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC"), 0)){};

	Circonscription Circonscription1;

};

TEST_F(circonscriptionTest, InscrireValide)
{
	Adresse Adresse1(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	Date Date1(01,01,2001);
	Candidat Candidat2("640454286", "Bob", "Blo", Date1, Adresse1, 0);
	//Circonscription1.inscrire(Candidat2);
}

TEST(Adresse, ConstructeurNInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(235, "", "Québec", "G1V 0A7", "QC");,PreconditionException);
}

TEST(Adresse, ConstructeurNomVilleInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(235, "rue de l'Université", "", "G1V 0A7", "QC");,PreconditionException);
}

TEST(Adresse, ConstructeurCodePostalInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(235, "rue de l'Université", "Québec", "", "QC");,PreconditionException);
}

TEST(Adresse, ConstructeurProvinceInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "");,PreconditionException);
}

TEST(Adresse, reqNumeroCivic)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNumeroCivic(),235);
}

TEST(Adresse, reqNomRue)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNomRue(),"rue de l'Université");
}

TEST(Adresse, reqVille)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNomRue(),"Québec");
}

TEST(Adresse, reqCodePostal)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNomRue(),"G1V 0A7");
}

TEST(Adresse, reqProvince)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNomRue(),"QC");
}

TEST(Adresse, operateurEgalite)
{
	Adresse uneAdresse1(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	Adresse uneAdresse2(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse1 == uneAdresse2, true);
}

TEST(Adresse, reqAdresseFormateValide)
{
	Adresse uneAdresse1(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	std::string uneAdresse2 = "235, rue de l'Université, Québec, G1V 0A7, QC";
	ASSERT_EQ(uneAdresse2, uneAdresse1.reqAdresseFormate());
}
