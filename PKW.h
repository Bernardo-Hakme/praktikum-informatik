/*
 * PKW.h
 *
 *  Created on: Nov 26, 2025
 *      Author: bernardo_hakme
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug {
private:
	double p_dVerbrauch;	// L/100km
	double p_dTankVolumen;	// L
	double p_dTankInhalt;	// L

public:
	PKW();
	virtual ~PKW();

	PKW(std::string name, double maxGeschwindigkeit, double verbrauch, double tankvolumen=55.0);

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

	virtual void vSimulieren() override;

	virtual void vAusgeben() const override;

};

#endif /* PKW_H_ */
