/*
 * main.cpp
 *
 *  Created on: Nov 16, 2025
 *      Author: bernardo_hakme
 */
#include "Fahrzeug.h"

void vAufgabe_1() {
	//statische Objekterzeugung
	Fahrzeug auto1("Audi");
	Fahrzeug schiff1;
	Fahrzeug motorrad1("Yamaha");

	//dynamische Objekterzeugung

	/*zeiger-auf-Fahrzeug(type) namens "auto2", der auf einen
	erzeugten Fahrzeug (mit parameter), zeigt*/

	Fahrzeug* pAuto2 = new Fahrzeug("BMW");
	Fahrzeug* pSchiff2 = new Fahrzeug();
	Fahrzeug* pMotorrad2 = new Fahrzeug("Yamaha");

	//Nutzen der Smartpointers
	std::unique_ptr<Fahrzeug> pUniqueAuto1 = std::make_unique<Fahrzeug> ("G-Wagon");
	std::unique_ptr<Fahrzeug> pUniqueAuto2 = std::make_unique<Fahrzeug> ("AMG");

	//std::unique_ptr<Fahrzeug> pUniqueAuto3 = pUniqueAuto1;
	/*Compiliert nicht und zeigt ein Fehler, da unique_ptr die einzigen
	 zeigern/besitzern auf ein objekt sein dürfen ("unique") */

	//shared-pointer
	std::shared_ptr<Fahrzeug> sharedMotorrad = std::make_shared<Fahrzeug> ("XRE");
	std::shared_ptr<Fahrzeug> sharedBus = std::make_shared<Fahrzeug> ("Mercedes");

	std::cout << "\nUse count sharedMotorrad (bevor): " << sharedMotorrad.use_count() << std::endl;

	std::shared_ptr<Fahrzeug> sharedMotorradCopy = sharedMotorrad; //ERLAUBT (shared_ptr)
	/*shared_ptr dürfen mehrere zeigern/besitzern auf ein objekt haben ("shared") */

	std::cout << "Use count sharedMotorrad (danach): " << sharedMotorrad.use_count() << std::endl;
	std::cout << "Use count sharedMotorradCopy: " << sharedMotorrad.use_count() << "\n" << std::endl;
	//Oben, zeigt sharedMotorradCopy auch 2, weil beide haben zugang zu den selben platz

	//Vector unique_ptr erzeugen
	std::vector<std::unique_ptr<Fahrzeug>> uniqueFahrzeuge;

	uniqueFahrzeuge.push_back(std::move(pUniqueAuto1)); //wechselt den besitzer des pUniqueAuto1 zeiger
	uniqueFahrzeuge.push_back(std::move(pUniqueAuto2)); //wechselt den besitzer des pUniqeuAuto2 zeiger

	uniqueFahrzeuge.clear(); //Löscht den Array

	//Vector shared_ptr erzeugen -- > TODO
	std::vector<std::shared_ptr<Fahrzeug>> sharedFahrzeuge;

	sharedFahrzeuge.push_back(std::move(sharedMotorrad));
	//Mit dem move hat das objekt 2 besitzern: sharedMotorradCopy + Vektor, da sharedMotorrad mit move auf den Vektor gelandet ist
	std::cout << "\nsharedMotorrad (nach push_back mit move): " << sharedMotorrad.use_count() << std::endl;
	std::cout << "sharedMotorradCopy: " << sharedMotorradCopy.use_count() << std::endl;

	sharedFahrzeuge.push_back(sharedMotorradCopy);
	std::cout << "sharedMotorradCopy (nach push_back ohne move): " << sharedMotorradCopy.use_count() << "\n" <<std::endl;

	//Löschen der dynamisch erzeugte Objekte
	delete pMotorrad2;
	delete pSchiff2;
	delete pAuto2;
}

void vAufgabe_1a()
{
	//Vektor für generierte Fahrzeuge erstellen
	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

	//eingaben einlesen
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Name: ";
		std::string sName;
		std::cin >> sName;

		std::cout << "max Geschwindigkeit: ";
		double dGeschwindigkeit;
		std::cin >> dGeschwindigkeit;

		fahrzeuge.push_back(std::make_unique<Fahrzeug>(sName, dGeschwindigkeit));
		std::cout << std::endl;
	}

	//Kopf der Tabelle
	Fahrzeug::vKopf();

	//Simulationsparameter (in stunden)
	double simZeit = 3.0;
	double zeitSchritt = 0.5;


	int sizeVector = fahrzeuge.size();
	while (dGlobaleZeit < simZeit)
	{
		dGlobaleZeit += zeitSchritt;

		for (int i = 0; i < sizeVector; i++)
		{
			(*fahrzeuge[i]).vSimulieren();
			(*fahrzeuge[i]).vAusgeben();
			std::cout << std::endl;
		}
	}
}

int main() {
	//code here
	vAufgabe_1();
	vAufgabe_1a();
}


