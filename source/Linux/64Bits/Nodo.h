#ifndef NODO_H
#define NODO_H
#include <cstdlib>
#include <cstdint>

class Nodo{
	public:
	int64_t dato;
    Nodo *sig;
    Nodo();
    Nodo(int64_t);
};

#endif
