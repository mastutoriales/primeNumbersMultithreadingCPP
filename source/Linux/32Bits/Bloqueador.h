#ifndef BLOQUEADOR_H
#define BLOQUEADOR_H

#include <atomic>

class Bloqueador
{
	public:
		void lock();
		void unlock();
	private:
		std::atomic_flag locked;
};

#endif
