#pragma once

#include "Body.h"

#include <cmath>

class BodyMassive : public Body
{
private:
public:
	BodyMassive(double, double, QVector2D);

	double tau_fun();
	double r_fun(double);
	double phi_fun();
	bool change_sign(double);
	void gravitational_red_or_blue_shift(double, double) {};

	bool is_massive() { return true; };
	std::array<double, COLOR_SPACE> get_RGBA() { return m_RGBA; };
};