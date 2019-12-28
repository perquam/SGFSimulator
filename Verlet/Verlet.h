#pragma once

#include "ui_Verlet.h"
#include "Calculations.h"

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QMutex>
#include <random>

class Verlet : public QMainWindow
{
	Q_OBJECT
public:
	Verlet(QWidget *parent = Q_NULLPTR);
	~Verlet();
private:
	Ui::VerletClass ui;
	Calculations *calculations;
	QObject* my_thingy;
	QTimer timer;
	QRandomGenerator gen;
	const quint32 begin = 100000;
	const quint32 end = 0;
private slots:
	void clickedPoint(QMouseEvent *event);
	void updateCounters();
};
