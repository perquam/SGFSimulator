#include "GLWidget.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent), mutex(QMutex::Recursive)
{
	initializeGL();
}

GLWidget::~GLWidget()
{
	for (std::vector<Body *>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		delete *i;
	}
	vec.clear();
}

void GLWidget::initializeGL()
{
	glClearColor(0, 0, 0, 1);
	glEnable(GL_POINT_SMOOTH);
	glMatrixMode(GL_PROJECTION);
}

void GLWidget::paintEvent(QPaintEvent *event)
{
	update();
}
	
void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glLoadIdentity();
	updateGL();
}

void GLWidget::addBodyMassive(double E, double l, QVector2D position)
{
	mutex.lock();
	double r = position.length();
	double expression = (1 - 2. * 5. / r); // M = 5;
	double Veff2 = expression * (pow(l, 2.) / pow(r, 2.) + 1.);
	double E2 = pow(E, 2.);
	if (E2 > Veff2)
		vec.emplace_back(new BodyMassive(E, l, position)); // Add condition for Massive bodies.
	mutex.unlock();
}

void GLWidget::addBodyMassless(double E, double l, QVector2D position, unsigned short wavelength)
{
	mutex.lock();
	double r = position.length();
	double expression = (1 - 2. * 5. / r);
	double Veff2 = expression * pow(l, 2.) / pow(r, 2.);
	double E2 = pow(E, 2.);
	if (E2 > Veff2)
		vec.emplace_back(new BodyMassless(E, l, position, wavelength)); // Add condition for Massless bodies.
	mutex.unlock();
}

void GLWidget::update()
{
	mutex.lock();

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.beginNativePainting();
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WINDOW_WIDTH,  0, WINDOW_HEIGHT, -1., 1.);

	for (auto &b : vec)
	{
		glBegin(GL_POLYGON);
		glColor4f(b->get_RGBA()[0], b->get_RGBA()[1], b->get_RGBA()[2], 1.);
		for (int i = 0; i < 360; i++)
		{
			double theta = i * 3.142 / 180;
			glVertex2f(b->get_size()*cos(theta)+ b->get_position().x() + WINDOW_WIDTH / 2, b->get_size()*sin(theta)+(-b->get_position().y())+ WINDOW_HEIGHT / 2);
		}
		glEnd();

		glBegin(GL_POINTS);
		for (auto &to : b->get_trajectory_object())
		{
			glColor4f(to.m_colors[0], to.m_colors[1], to.m_colors[2], 1.);
			glVertex2f(to.m_position.x() + WINDOW_WIDTH / 2, (-to.m_position.y()) + WINDOW_HEIGHT / 2);
		}
		glEnd();
	}

	glColor4f(1., 0., 0., 0.5);
	glBegin(GL_POLYGON);
	const double black_hole_size = 10.;
	for (int i = 0; i < 360; i++)
	{
		double theta = i * 3.142 / 180;
		glVertex2f(black_hole_size * cos(theta) + WINDOW_WIDTH / 2, black_hole_size * sin(theta) + WINDOW_HEIGHT / 2);
	}
	glEnd();
	painter.endNativePainting();

	if (m_checkbox_state == Qt::Checked)
	{
		painter.setRenderHint(QPainter::TextAntialiasing);
		painter.setPen(Qt::white);
		painter.setFont(QFont("Verdana", 5));
		for (auto &b : vec)
		{
			QString r, l;
			r.setNum(b->get_r());
			l.setNum(b->get_l());
			QString body_informations = r + " " + l;
			painter.drawText((int)(b->get_position().x() - 20 + WINDOW_WIDTH / 2), (int)(b->get_position().y() + 15 + WINDOW_HEIGHT / 2), body_informations);
		}
	}

	painter.end();
	mutex.unlock();
}

void GLWidget::MouseEvents(QMouseEvent *e)
{
	mutex.lock();
	if (e->button() == Qt::LeftButton)
		emit mousePressEvent(e);
	mutex.unlock();
}

std::vector<Body*> & GLWidget::getVec()
{
	return vec;
}

void GLWidget::is_checkbox_checked(int checkbox_state)
{
	m_checkbox_state = checkbox_state;
}

void GLWidget::clear()
{
	mutex.lock();
	for (std::vector<Body *>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		(*i)->get_trajectory_object().clear();
		delete *i;
	}
	vec.clear();
	mutex.unlock();
}