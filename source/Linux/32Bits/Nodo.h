#ifndef NODO_H
#define NODO_H
#include <cstdlib>
#include <cstdint>

class Nodo
{
	public:
	int dato;
        Nodo *sig;
        Nodo();
        Nodo(int);
};

#endif
