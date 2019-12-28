#include "Body.h"
#include "BodyMassive.h"
#include "BodyMassless.h"

#include <functional>

RungeKutta5th Body::next_value;

Body::Body(double E, double l, QVector2D position)
{
	m_position = position;
	m_r = m_position.length();
	m_E = E;
	m_l = l;
	if (m_position.x() >= 0.)
		m_phi = asin(m_position.y() / m_r);
	else
	{
		double sign = m_position.y() / abs(m_position.y());
		m_phi = asin(m_position.y() / m_r) + sign * 2. * (1.57 - sign * asin(m_position.y() / m_r)); // Change 1.57 to M_PI / 2.
	}
}

void Body::update(Body & b)
{
	if (b.is_massive())
	{
		BodyMassive & b_m = static_cast<BodyMassive &>(b);

		auto tau_fun = std::bind(&BodyMassive::tau_fun, &b_m);
		auto phi_fun = std::bind(&BodyMassive::phi_fun, &b_m);
		auto r_fun = std::bind(&BodyMassive::r_fun, &b_m, std::placeholders::_1);

		if (this->m_trajectory_object.empty())
		{
			this->m_trajectory_object.push_back(TrajectoryObject(m_position, this->m_RGBA));
		}
		else
		{
			std::vector<TrajectoryObject>::iterator i = this->m_trajectory_object.end();
			--i;
			double d = 5.;
			if (i->m_position.distanceToPoint(m_position) > d)
				this->m_trajectory_object.push_back(TrajectoryObject(m_position, this->m_RGBA));
		}

		this->calculate_expression(this->get_r());
		this->m_tau = next_value.next_step(tau_fun, this->get_tau());
		this->m_phi = next_value.next_step(phi_fun, this->get_phi());
		double r_tmp = next_value.next_step(r_fun, this->get_r());
		this->calculate_expression(r_tmp);
		if (this->change_sign(r_tmp))
		{
			this->calculate_expression(this->get_r());
			this->m_r = next_value.next_step(r_fun, this->get_r());
		}
		else
			this->m_r = r_tmp;

		this->m_position.setX(m_r * cos(m_phi));
		this->m_position.setY(m_r * sin(m_phi));
	}
	else
	{
		BodyMassless & b_m = static_cast<BodyMassless &>(b);

		auto tau_fun = std::bind(&BodyMassless::tau_fun, &b_m);
		auto phi_fun = std::bind(&BodyMassless::phi_fun, &b_m);
		auto r_fun = std::bind(&BodyMassless::r_fun, &b_m, std::placeholders::_1);

		if (this->m_trajectory_object.empty())
		{
			this->m_trajectory_object.push_back(TrajectoryObject(m_position, this->m_RGBA));
		}
		else
		{
			std::vector<TrajectoryObject>::iterator i = this->m_trajectory_object.end();
			--i;
			double d = 5.;
			if (i->m_position.distanceToPoint(m_position) > d)
				this->m_trajectory_object.push_back(TrajectoryObject(m_position, this->m_RGBA));
		}

		this->calculate_expression(this->get_r());
		this->m_tau = next_value.next_step(tau_fun, this->get_tau());
		this->m_phi = next_value.next_step(phi_fun, this->get_phi());
		double r_tmp = next_value.next_step(r_fun, this->get_r());
		this->calculate_expression(r_tmp);
		if (this->change_sign(r_tmp))
		{
			this->calculate_expression(this->get_r());
			double r_tmp_2 = this->get_r();
			this->m_r = next_value.next_step(r_fun, this->get_r());
			this->gravitational_red_or_blue_shift(r_tmp_2, this->get_r());
		}
		else
		{
			this->gravitational_red_or_blue_shift(this->get_r(), r_tmp);
			this->m_r = r_tmp;
		}

		this->m_position.setX(m_r * cos(m_phi));
		this->m_position.setY(m_r * sin(m_phi));
	}
}

void Body::calculate_expression(double r)
{
	this->expression = (1 - 2. * m_M / r);
}

double Body::get_M()
{
	return m_M;
}

int Body::get_G()
{
	return m_G;
}

QVector2D Body::get_position()
{
	return m_position;
}

double Body::get_size()
{
	return m_size;
}

double Body::get_l()
{
	return m_l;
}

double Body::get_tau()
{
	return m_tau;
}

double Body::get_phi()
{
	return m_phi;
}

double Body::get_r()
{
	return m_r;
}

void Body::change_size(double size)
{
	m_size = size;
}

std::vector<TrajectoryObject> & Body::get_trajectory_object()
{
	return m_trajectory_object;
}