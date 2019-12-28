#pragma once

#include "Body.h"

#include <cmath>

class BodyMassless : public Body
{
private:
	double m_wavelength;
public:
	BodyMassless(double, double, QVector2D, double);

	double tau_fun();
	double r_fun(double);
	double phi_fun();
	void gravitational_red_or_blue_shift(double, double);
	void wavelength_to_RGB();
	bool change_sign(double);

	bool is_massive() { return false; };
	std::array<double, COLOR_SPACE> get_RGBA() { return m_RGBA; };
};