#include "Verlet.h"
#include <QVector2D>
#include <QScreen>

Verlet::Verlet(QWidget *parent)
	: QMainWindow(parent), gen(&begin, &end)
{
	ui.setupUi(this);

	my_thingy = new QObject(this);
	calculations = new Calculations(my_thingy, ui.widget->getVec(), ui.widget->mutex, this);

	timer.start(20);
	connect(&timer, SIGNAL(timeout()), ui.widget, SLOT(update()));
	connect(&timer, SIGNAL(timeout()), this, SLOT(updateCounters()));

	connect(ui.widget, SIGNAL(mousePressEvent(QMouseEvent *)), this, SLOT(clickedPoint(QMouseEvent *)));
	connect(ui.show_parameters, SIGNAL(stateChanged(int)), ui.widget, SLOT(is_checkbox_checked(int)));
	connect(ui.restart, SIGNAL(released()), ui.widget, SLOT(clear()));
	connect(ui.clear, SIGNAL(released()), ui.widget, SLOT(clear()));
}

Verlet::~Verlet()
{
	delete calculations;
}

void Verlet::clickedPoint(QMouseEvent *event)
{
	QPoint point = event->pos();
	point.setX(point.x() - 350); // WINDOW_WIDTH / 2
	point.setY(point.y() - 350);
	QVector2D position(point.x(), point.y());
	if (ui.nob_spinbox->value() == 1)
	{
		if (event->button() == Qt::LeftButton)
			ui.widget->addBodyMassive(ui.e_spinbox->value(), ui.l_spinbox->value(), position); // Add E and l.
		else
			ui.widget->addBodyMassless(ui.e_spinbox->value(), ui.l_spinbox->value(), position, ui.wavelength_spinbox->value());
	}
	else
	{
		if (event->button() == Qt::LeftButton)
		{
			for (int i = 0; i < ui.nob_spinbox->value(); i++)
			{
				double random_val = gen.generateDouble() * 100.;
				ui.widget->addBodyMassive(ui.e_spinbox->value(), random_val, position); // Add E and l.
			}
		}
		else
		{
			for (int i = 0; i < ui.nob_spinbox->value(); i++)
			{
				double random_val = gen.generateDouble() * 100.;
				ui.widget->addBodyMassless(ui.e_spinbox->value(), random_val , position, ui.wavelength_spinbox->value());
			}
		}
	}
}

void Verlet::updateCounters()
{
	const QPoint global_mouse_position(QCursor::pos().x(), QCursor::pos().y());
	QPoint local_mouse_position = (ui.widget)->mapFromGlobal(global_mouse_position);
	QVector2D pos(local_mouse_position);
	pos.setX(pos.x() - 350);
	pos.setY(pos.y() - 350);
	QString string_number = QString::number(pos.length());
	ui.distance_labelbox->setText(string_number);
}
