// ApplicationMedical.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Attribut.h"
#include "AttributString.h"
#include "AttributDouble.h"
#include "Empreinte.h"
#include "GestionDonnees.h"
#include "GestionFichier.h"
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

	// GestionDonnees gd;

	// unordered_map<string, double> res = gd.analyse(e);
	// gd.associerMaladieEmpreinte("Maladie1", e);

	// Empreinte e1 = gd.trouverEmpreinteParID(2);

	// Main

	int choixMenu = 0, choixEmpreinte = 0, choixAjoutMaladie = 0;

	GestionDonnees gestionDonnees;
	GestionFichier gestionFichier;

	Maladie maladie;
	string nomMaladie = "";
	int idEmpreinteMaladie;
	Empreinte empreinteMaladie;
	int nombreEmpreintes;
	list<Empreinte> listeEmpreintesMaladie;

	vector<Attribut *> listeAttributs;
	Attribut *a1, *a2, *a3, *a4, *a5;

	string attributString;
	double attributDouble;

	Empreinte empreinte;
	int idEmpreinte = 1;
	string maladieEmpreinte = "";

	do
	{
		cout << endl;
		cout << "Analyse Médicale - TP GL UML 3IF" << endl;
		cout << endl;
		cout << "1- Analyser une empreinte" << endl;
		cout << "2- Afficher les maladies prises en compte" << endl;
		cout << "3- Afficher les caractéristiques d'une maladie" << endl;
		cout << "4- Ajouter une empreinte" << endl;
		cout << "5- Quitter" << endl;
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
					cout << "Choisir l'identifiant de l'empreinte à analyser" << endl;
					gestionFichier.affichageEmpreintes();
					cin >> idEmpreinteMaladie;
					empreinteMaladie = gestionDonnees.trouverEmpreinteParID(idEmpreinteMaladie);
					gestionDonnees.analyse(empreinteMaladie);
					break;

				case 2:
					cout << "Analyser un ensemble d'empreinte" << endl;
					cout << "Nombre d'empreinte à analyser : " << endl;
					cin >> nombreEmpreintes;
					cout << "Choisir les identifiants des empreintes à analyser" << endl;
					gestionFichier.affichageEmpreintes();
					for (int i; i < nombreEmpreintes; ++i)
					{
						cin >> idEmpreinteMaladie;
						empreinteMaladie = gestionDonnees.trouverEmpreinteParID(idEmpreinteMaladie);
						listeEmpreintesMaladie.push_back(empreinteMaladie);
					}
					gestionDonnees.analyse(listeEmpreintesMaladie);
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
			gestionFichier.affichageMaladies();
			break;

		case 3:
			cout << "Afficher les caractéristiques d'une maladie" << endl;
			cout << endl;
			gestionFichier.affichageMaladies();
			cout << "Entrez nom de de la maladie :";
			cin >> nomMaladie;
			//TODO
			cout << endl;

			break;

		case 4:
			cout << "Ajouter une empreinte" << endl;

			cout << "entrez l'attribut A1 : ";
			cin >> attributString;
			a1 = new AttributString("A1", attributString);
			listeAttributs.push_back(a1);
			cout << endl;

			cout << "entrez l'attribut A2 : ";
			cin >> attributDouble;
			a2 = new AttributDouble("A2", attributDouble);
			listeAttributs.push_back(a2);
			cout << endl;

			cout << "entrez l'attribut A3 : ";
			cin >> attributDouble;
			a3 = new AttributDouble("A3", attributDouble);
			listeAttributs.push_back(a3);
			cout << endl;

			cout << "entrez l'attribut A4 : ";
			cin >> attributDouble;
			a4 = new AttributDouble("A4", attributDouble);
			listeAttributs.push_back(a4);
			cout << endl;

			cout << "entrez l'attribut AZ51 : ";
			cin >> attributDouble;
			a5 = new AttributDouble("AZ51", attributDouble);
			listeAttributs.push_back(a5);
			cout << endl;

			empreinte = Empreinte(idEmpreinte++, listeAttributs);
			cout << "L'empreinte " << idEmpreinte << " a été ajoutée:" << endl;

			cout << "Associer l'empreinte " << idEmpreinte << " à une maladie ?" << endl;
			cout << "1- Oui" << endl;
			cout << "2- Non" << endl;
			cout << "Entrez votre choix : ";
			cin >> choixEmpreinte;
			switch (choixEmpreinte)
			{
			case 1:
				cout << endl;
				gestionFichier.affichageMaladies();
				cout << "Entrez nom de de la maladie :";
				cin >> maladieEmpreinte;
				gestionDonnees.associerMaladieEmpreinte(maladieEmpreinte, empreinte);
				cout << "La maladie :" << maladieEmpreinte << " a bien été associée." << endl;
				break;

			case 2:
				cout << "Vos modifications ont bien été appliqués." << endl;
				break;

			default:
				cout << "Veuillez entrer un choix valide." << endl;
				break;
			}
			break;

		case 5:
			cout << "Vous avez quitté l'application." << endl;
			break;

		default:
			cout << "Veuillez entrer un choix valide." << endl;
			break;
		}

	} while (choixMenu != 6);

	return 0;
}
