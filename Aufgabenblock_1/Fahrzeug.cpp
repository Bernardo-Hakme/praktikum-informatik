/*
 * Fahrzeug.cpp
 *
 *  Created on: Nov 16, 2025
 *      Author: bernardo_hakme
 */

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

double dGlobaleZeit = 0.0;

Fahrzeug::Fahrzeug()
: p_sName(""), p_iID(++p_iMaxID)
{
	std::cout << "Name: kein Name" << " ID: " << p_iID << std::endl;
}

Fahrzeug::Fahrzeug(std::string name)
: p_sName(name), p_iID(++p_iMaxID)
{
	std::cout << "Name: " << p_sName << ", ID: " << p_iID << std::endl;
}

Fahrzeug::Fahrzeug(std::string name, double maxGeschwindigkeit)
: p_sName(name), p_iID(++p_iMaxID), p_dMaxGeschwindigkeit(maxGeschwindigkeit > 0 ? maxGeschwindigkeit : 0)
{
	std::cout << "Name: " << p_sName << ", Max. Geschwindigkeit: " << p_dMaxGeschwindigkeit << ", ID: " << p_iID << std::endl;
}

void Fahrzeug::vAusgeben()
{
	std::cout << std::setw(5) << p_iID
			<< std::setw(15) << p_sName
			<< std::setw(20) << std::fixed<< std::setprecision(2) << p_dMaxGeschwindigkeit
			<< std::setw(15) << std::fixed <<std::setprecision(2) << p_dGesamtStrecke;
}

void Fahrzeug::vKopf()
{
	std::cout << std::setw(5) << "ID"
			<< std::setw(15) << "Name"
			<< std::setw(20) << "MaxGeschwindigkeit"
			<< std::setw(15) << "GesamtStrecke" << std::endl;

	std::cout << std::setw(58) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
}

void Fahrzeug::vSimulieren()
{
	if (dGlobaleZeit == p_dZeit)
	{
		return;
	}

	double dZeitDifferenz = dGlobaleZeit - p_dZeit;
	double dAktuelleStrecke = p_dMaxGeschwindigkeit * dZeitDifferenz;
	p_dGesamtStrecke += dAktuelleStrecke;
	p_dGesamtZeit += dZeitDifferenz; //warum? --> TODO: code checken
	p_dZeit = dGlobaleZeit;
}

Fahrzeug::~Fahrzeug()
{
	std::cout << "Fahrzeug: " << p_sName << ", ID: " << p_iID << " gelöscht." << std::endl;
}

