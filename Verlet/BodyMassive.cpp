#include "BodyMassive.h"
#include <fstream>

BodyMassive::BodyMassive(double E, double l, QVector2D position) : Body(E, l, position)
{
	m_size = 5.;
	E2 = pow(m_E, 2.);
}

double BodyMassive::tau_fun()
{
	return (expression / m_E);
}

double BodyMassive::phi_fun()
{
	return ((expression * m_l) / (m_E * pow(m_r, 2.)));
}

double BodyMassive::r_fun(double r)
{
	double Veff2 = expression * (pow(m_l, 2.) / pow(r, 2.) + 1.);
	double expression_2 = E2 - Veff2;
	if (E2 <= Veff2)
		return 0.;
	else
		return plus_minus * (expression / m_E * sqrt(E2 - Veff2));
}

bool BodyMassive::change_sign(double r)
{
	double Veff2 = expression * (pow(m_l, 2.) / pow(r, 2.) + 1.);
	if (E2 <= Veff2)
	{
		plus_minus *= -1.;
		return true;
	}
	else
		return false;
}