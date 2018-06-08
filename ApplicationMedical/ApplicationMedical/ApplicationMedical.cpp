// ApplicationMedical.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Attribut.h"
#include "AttributString.h"
#include "AttributDouble.h"
#include "Empreinte.h"
#include "GestionDonnees.h"
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
	vector<Attribut *> list1;
	Attribut *a1 = new AttributString("A1", "False");
	list1.push_back(a1);
	Attribut *a2 = new AttributDouble("A2", 7.8);
	list1.push_back(a2);
	Attribut *a3 = new AttributDouble("A3", 80);
	list1.push_back(a3);
	Attribut *a4 = new AttributDouble("A4", 7.628);
	list1.push_back(a4);
	Attribut *a5 = new AttributDouble("AZ51", 68.5);
	list1.push_back(a5);
	Empreinte e(1, list1);

	GestionDonnees gd;

	unordered_map<string, double> res = gd.analyse(e);
	gd.associerMaladieEmpreinte("Maladie1", e);

	Empreinte e1 = gd.trouverEmpreinteParID(2);

	// Main

	int choixMenu = 0, choixEmpreinte = 0;
	GestionDonnees gestionDonnees;
	GestionDonnees gestionFichiers;

	do
	{
		cout << endl;
		cout << "Analyse Médicale - TP GL UML 3IF" << endl;
		cout << endl;
		cout << "1- Analyser une empreinte" << endl;
		cout << "2- Afficher les maladies prises en compte" << endl;
		cout << "3- Afficher les caractéristiques d'une maladie" << endl;
		cout << "4- Ajouter une empreinte" << endl;
		cout << "5- Associer une empreinte à une maladie" << endl;
		cout << "6- Quitter" << endl;
		cout << endl;
		cout << "Entrez votre choix : ";
		cin >> choixMenu;
		cout << endl;

		switch (choixMenu)
		{
		case 1:
			do
			{
				cout << endl;
				cout << "Analyser une empreinte" << endl;
				cout << endl;
				cout << "1- Analyser une empreinte" << endl;
				cout << "2- Analyser un ensemble d'empreinte" << endl;
				cout << "3- Quitter" << endl;
				cout << endl;
				cout << "Entrez votre choix : ";
				cin >> choixEmpreinte;
				cout << endl;

				switch (choixEmpreinte)
				{
				case 1:
					cout << "Analyser une empreinte" << endl;

					break;

				case 2:
					cout << "Analyser un ensemble d'empreinte" << endl;

					break;

				case 3:
					cout << "Vous avez quitté le menu d'analyse de l'empreinte" << endl;

					break;

				default:
					cout << "Veuillez entrer un choix valide." << endl;

					break;
				}

			} while (choixEmpreinte != 3);

			break;

		case 2:
			cout << "Afficher les maladies prises en compte" << endl;
			gestionDonnees.affichageMaladies();
			break;

		case 3:
			cout << "Afficher les caractéristiques d'une maladie" << endl;

			break;

		case 4:
			cout << "Ajouter une empreinte" << endl;

			break;

		case 5:
			cout << "Associer une empreinte à une maladie" << endl;

			break;

		case 6:
			cout << "Vous avez quitté l'application." << endl;
			break;

		default:
			cout << "Veuillez entrer un choix valide." << endl;
			break;
		}

	} while (choixMenu != 6);

	return 0;
}
