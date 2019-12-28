#include "Calculations.h"

Calculations::Calculations(QObject* thingy, std::vector<Body *> &vec, QMutex & mutex, QObject* parent)
	: QObject(0), m_vec(vec), m_mutex(mutex)
{
	my_thingy = thingy;

	thread = new QThread(parent);
	this->moveToThread(thread);
	thread->start();
	connect(thread, SIGNAL(started()), this, SLOT(do_calculations()));
}

Calculations::~Calculations()
{
	loop = false;
	thread->terminate();
	thread->wait();
	delete thread;
	delete my_thingy;
}

void Calculations::do_calculations()
{	
	while (loop)
	{
		m_mutex.lock();
		for (auto &b : m_vec)
		{
			b->update((*b));
		}
		m_mutex.unlock();
	}
}