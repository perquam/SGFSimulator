#include "Verlet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Verlet w;
	w.show();
	return a.exec();
}
