#pragma once

#include <QVector2D>

class TrajectoryObject
{
public:
	TrajectoryObject(QVector2D position, std::array<double, 4> colors) : m_position(position), m_colors(colors) {};

	double m_size = 1.;
	QVector2D m_position;
	std::array<double, 4> m_colors;
	double m_d = 1.;
};