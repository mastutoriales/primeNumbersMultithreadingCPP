#ifndef NODO_H
#define NODO_H
#include <cstdlib>

class Nodo
{
	public:
		__int64 dato;
        Nodo *sig;
        Nodo();
        Nodo(__int64);
};

#endif
