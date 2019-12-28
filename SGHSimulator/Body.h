#pragma once

#include "RungeKutta5th.h"
#include "TrajectoryObject.h"

//#include <QGLWidget>
#include <QVector2D>
#include <vector>

#define COLOR_SPACE 4

class Body
{
	static RungeKutta5th next_value;
	std::vector<TrajectoryObject> m_trajectory_object;
protected:
	const double m_G = 1.;
	const double m_M = 5.;		// It sets the curvature around the center of the coorinate system.
	const double m_c = 1;
	double m_size;
	double m_E;
	double E2;
	double m_l;
	double m_tau;
	double m_r;
	double m_phi;
	double plus_minus = -1.;
	double expression;
	QVector2D m_position;
	std::array<double, COLOR_SPACE> m_RGBA = { 1., 0., 0., 1. };
public:
	Body(double, double, QVector2D);
	void update(Body & b);
						// Getters and setters.
	void calculate_expression(double);
	virtual double tau_fun() = 0;
	virtual double r_fun(double) = 0;
	virtual double phi_fun() = 0;
	virtual bool change_sign(double) = 0;
	virtual void gravitational_red_or_blue_shift(double, double) = 0;

	virtual bool is_massive() = 0;
	virtual std::array<double, COLOR_SPACE> get_RGBA() = 0;

	double get_size();
	QVector2D get_position();
	double get_M();
	int get_G();
	double get_l();
	double get_tau();
	double get_phi();
	double get_r();
	std::vector<TrajectoryObject> & get_trajectory_object();
public slots:
	void set_position(double);
	void change_size(double);
};