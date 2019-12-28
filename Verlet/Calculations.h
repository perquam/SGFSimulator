#pragma once
#include "BodyMassive.h"
#include "BodyMassless.h"
#include "TrajectoryObject.h"

#include <QtWidgets>
#include <vector>
#include <QMutex>

class Calculations : public QObject
{
	Q_OBJECT
public:
	Calculations(QObject *thingy, std::vector<Body *> &, QMutex & mutex, QObject *parent = 0);
	~Calculations();

private:
	QObject* my_thingy;
	QThread* thread;
	QMutex & m_mutex;

	bool loop = true;

	std::vector<Body *> & m_vec;
private slots:
	void do_calculations();
};