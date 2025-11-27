/*
 * PKW.cpp
 *
 *  Created on: Nov 26, 2025
 *      Author: bernardo_hakme
 */

#include "PKW.h"

//PKW::PKW() : Fahrzeug() {}

PKW::PKW(std::string name, double maxGeschwindigkeit, double verbrauch, double tankvolumen)
: Fahrzeug(name, maxGeschwindigkeit),
  p_dVerbrauch(verbrauch),
  p_dTankVolumen(tankvolumen),
  p_dTankInhalt(tankvolumen / 2.0)
{}


PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

