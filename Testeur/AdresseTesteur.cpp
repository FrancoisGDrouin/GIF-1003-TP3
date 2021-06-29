#include <gtest/gtest.h>
#include "Adresse.h"
#include "ContratException.h"

using namespace util;

TEST(Adresse, ConstructeurValide)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNumeroCivic(),235);
	ASSERT_EQ(uneAdresse.reqNomRue(),"rue de l'Université");
	ASSERT_EQ(uneAdresse.reqVille(),"Québec");
	ASSERT_EQ(uneAdresse.reqCodePostal(),"G1V 0A7");
	ASSERT_EQ(uneAdresse.reqProvince(),"QC");
}

TEST(Adresse, ConstructeurNumeroInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(-235, "rue de l'Université", "Québec", "G1V 0A7", "QC");,PreconditionException);
}

TEST(Adresse, ConstructeurNomRueInvalide)
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

