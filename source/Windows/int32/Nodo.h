#ifndef NODO_H
#define NODO_H
#include <cstdlib>

class Nodo
{
	public:
		__int32 dato;
        Nodo *sig;
        Nodo();
        Nodo(__int32);
};

#endif
