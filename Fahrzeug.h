/*
 * Fahrzeug.h
 *
 *  Created on: Nov 16, 2025
 *      Author: bernardo_hakme
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <iomanip>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <limits>

//Deklaration globale variable Zeit (Aufgabe 4.2.7)
extern double dGlobaleZeit; // wie viele stunden sollen fahrzeuge simulieren

class Fahrzeug {
private:
	std::string p_sName;
	static int p_iMaxID;
	const int p_iID {};

protected:
	double p_dMaxGeschwindigkeit = 0; //max.geschw des fahrzeugs
	double p_dGesamtStrecke = 0; // bisher zurückgelegte strecke
	double p_dGesamtZeit = 0; // gesamte fahrzeit
	double p_dZeit = 0; //wann fahrzeug zuletzt simuliert wurde

public:
	Fahrzeug();
	Fahrzeug(std::string name);

	Fahrzeug(std::string name, double maxGeschwindigkeit);


	virtual void vAusgeben() const; //ändert nicht
	static void vKopf();

	virtual void vSimulieren(); //kann bei PKW und Fahrrad unterschiedlich sein

	virtual double dGeschwindigkeit() const;

	virtual ~Fahrzeug();
};

#endif /* FAHRZEUG_H_ */
