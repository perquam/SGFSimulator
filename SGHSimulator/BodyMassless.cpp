#include "BodyMassless.h"

BodyMassless::BodyMassless(double E, double l, QVector2D position, double wavelength) : Body(E, l, position)
{
	m_size = 2.;
	E2 = pow(m_E, 2.);
	m_wavelength = wavelength;
}

double BodyMassless::tau_fun()
{
	return (expression / m_E);
}

double BodyMassless::phi_fun()
{
	return ((expression * m_l) / (m_E * pow(m_r, 2.)));
}

double BodyMassless::r_fun(double r)
{
	double Veff2 = expression * pow(m_l, 2.) / pow(r, 2.);
	double expression_2 = E2 - Veff2;
	if (E2 <= Veff2)
		return 0;
	else
		return plus_minus * (expression / m_E * sqrt(E2 - Veff2));
}

void BodyMassless::gravitational_red_or_blue_shift(double r_prev, double r)
{
	m_wavelength = sqrt((1 - 2. * m_M / r) / (1 - 2. * m_M / r_prev)) * m_wavelength;
	wavelength_to_RGB();
}

void BodyMassless::wavelength_to_RGB()
{
	float R = 0.0;
	float G = 0.0;
	float B = 0.0;
	if ((m_wavelength >= 380.0) && (m_wavelength <= 410.0))
	{ R = 0.6 - 0.41 * (410.0 - m_wavelength) / 30.0; G = 0.0;   B = 0.39 + 0.6 * (410.0 - m_wavelength) / 30.0; }
	else if ((m_wavelength >= 410.0) && (m_wavelength <= 440.0)) { R = 0.19 - 0.19 * (440.0 - m_wavelength) / 30.0;   G = 0.0;   B = 1.0; }
	else if ((m_wavelength >= 440.0) && (m_wavelength <= 490.0)) { R = 0;   G = 1 - (490.0 - m_wavelength) / 50.0;   B = 1.0; }
	else if ((m_wavelength >= 490.0) && (m_wavelength <= 510.0)) { R = 0;   G = 1;   B = (510.0 - m_wavelength) / 20.0; }
	else if ((m_wavelength >= 510.0) && (m_wavelength <= 580.0)) { R = 1 - (580.0 - m_wavelength) / 70.0;   G = 1;   B = 0; }
	else if ((m_wavelength >= 580.0) && (m_wavelength <= 640.0)) { R = 1;   G = (640.0 - m_wavelength) / 60.0;   B = 0; }
	else if ((m_wavelength >= 640.0) && (m_wavelength <= 700.0)) { R = 1; G = 0;   B = 0; }
	else if ((m_wavelength >= 700.0) && (m_wavelength <= 780.0)) { R = 0.35 + 0.65 * (780.0 - m_wavelength) / 80.0;   G = 0;   B = 0; }
	m_RGBA[0] = R;
	m_RGBA[1] = G;
	m_RGBA[2] = B;
}

bool BodyMassless::change_sign(double r)
{
	double Veff2 = expression * pow(m_l, 2.) / pow(r, 2.);
	if (E2 <= Veff2)
	{
		plus_minus *= -1;
		return true;
	}
	else
		return false;
}
