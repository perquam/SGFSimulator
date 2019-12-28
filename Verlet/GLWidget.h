#pragma once
#include "BodyMassive.h"
#include "BodyMassless.h"
#include "TrajectoryObject.h"

#include <QGLWidget>
#include <QTimer>
#include <vector>
#include <QMouseEvent>
#include <math.h>
#include <QMutex>

class GLWidget : public QGLWidget
{
	Q_OBJECT
private:
	std::vector<Body *> vec;
	const int WINDOW_WIDTH = 700, WINDOW_HEIGHT = 700;
	int m_checkbox_state;
public:
	explicit GLWidget(QWidget *parent = 0);
	~GLWidget();

	void initializeGL();
	void paintEvent(QPaintEvent *event);
	void resizeGL(int w, int h);
	void addBodyMassive(double, double, QVector2D);
	void addBodyMassless(double, double, QVector2D, unsigned short);

	std::vector<Body *> & getVec();

	void MouseEvents(QMouseEvent *e);

	QMutex mutex;
signals:
	void mousePressEvent(QMouseEvent *);

public slots:
	void clear();
	void update();
	void is_checkbox_checked(int);
};