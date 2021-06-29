//validationFormat.cpp

#include <iostream>
#include <sstream>
#include <string>

bool validerNas(const string& p_nas)
{
	istringstream lectureNas(p_nas);
	int premierTier, deuxiemeTier, troisiemeTier;
    lectureNas >> premierTier;
    lectureNas >> deuxiemeTier;
    lectureNas >> troisiemeTier;

    int arrNas[9];
	arrNas[0] = premierTier/100 % 10;
	arrNas[1] = premierTier/10 % 10;
	arrNas[2] = premierTier % 10;
	arrNas[3] = deuxiemeTier/100 % 10;
	arrNas[4] = deuxiemeTier/10 % 10;
	arrNas[5] = deuxiemeTier % 10;
	arrNas[6] = troisiemeTier/100 % 10;
	arrNas[7] = troisiemeTier/10 % 10;
	arrNas[8] = troisiemeTier % 10;

	int somme = 0;
    //on regarde seulement les NAS pour citoyens permanents (entre 000 000 000 et 899 999 999)
    //chaque tier doit être entre 0 et 999, sauf le premier qui doit être inférieur à 900
    if(premierTier >= 0 && premierTier <= 899 && deuxiemeTier >= 0 && deuxiemeTier <= 899 && troisiemeTier >= 0 && troisiemeTier <= 899)
    {
    	for(int i=0; i<9; i++) //on itère sur les 9 caractères du NAS
    	{
    		if(i % 2 == 1) //impair i={1, 3, 5, 7} PremierTier[1], DeuxiemeTier[0], DeuxiemeTier[2], TroisiemeTier[1]
    		{
    			if((2*arrNas[i]) >= 10) //si la multiplication par le facteur de 2 est plus grande que 10
    			{
    				somme = somme + (2*arrNas[i]) - 9; //on additionne les caractères du nombre obtenu
    			}
    			else
    			{
    				somme = somme + (2*arrNas[i]); //sinon, on additionne les nombres multipliés par 2
    			}
    		}
    		else //impair ou zéro
    		{
    			somme = somme + arrNas[i];
    		}
    	}
    }
	else
	{
		cout << "Les nombres du NAS sont invalides" << endl;
    }

    if(somme % 10 == 0)
    {
    	cout << "NAS valide" << endl;
    	return true;
    }
    else
    {
    	cout << "NAS invalide" << endl;
    	return false;
    }
}


/*bool validerFormatFichier(std::istream& p_is)

//valider sur la ligne du NAS que le premier caractère est un chiffre (.isalpha())

int compteurLignes = 0;
string ligneActuelle;

int flagParti = 0;
int flagPrenom = 0;
int flagNom = 0;
int flagNas = 0;
int flagDate = 0;

//si ligneActuelle commence par une lettre
while (getline(p_is, ligneActuelle)) {
    if (isalpha.(ligneActuelle[0])){
        int flag = 0;
    } 
    else if (ligneActuelle.empty()){
        return false;
    }
    //si ligneActuelle commence par un chiffre
    else {
        int flag = 1;
    }

    switch (flag) {
    case 0:
        if (compteurLignes == 0) && (ligneActuelle.find("Circonscription") != string::npos){
            break;
        }
        else if (compteurLignes == 0) && (ligneActuelle.find("Circonscription") == string::npos){
            return false;
        }
        if flagParti = 0 {
        //vérifier si ligneActuelle = parti
            switch (ligneActuelle) {
                case "BLOC_QUEBECOIS":
                    flagParti = 1;
                    break;
                case "CONSERVATEUR":
                    flagParti = 1;
                    break;
                case "INDEPENDANT":
                    flagParti = 1;
                    break;
                case "LIBERAL":
                    flagParti = 1;
                    break;
                case "NOUVEAU_PARTI_DEMOCRATIQUE":
                    flagParti = 1;
                    break;
                default:
                    return false;
                }
            break;
        //vérifier si ligneActuelle = prénom, nom ou adresse
            }
        else if (flagPrenom = 0) {
            flagPrenom = 1;
            break;
        }
        else if (flagNom = 0) {
            flagNom = 1;
            break;
        }
        else {
            int flagParti = 0;
            int flagPrenom = 0;
            int flagNom = 0;
            break;
        }
    case 1:
        if (flagNas = 0) {
            flagNas = 1;
            break;
        }
        else if (flagDate = 0) {
            flagDate = 1;
            break;
        }

    }
}
