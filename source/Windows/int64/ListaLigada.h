#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "Nodo.h"
#include <cstdlib>
#include <iostream>

class ListaLigada
{
	private:
		Nodo*  head;
		Nodo* tail;
		Nodo* pos;
		Nodo* t;
	public:
		friend void run();
		friend void guardar(std::string);
		friend __int64 maxCarga();
		ListaLigada();
		~ListaLigada();
		void agregar (__int64);
		__int64 eliminar();
		bool vacia();
		__int64 valor();
		void reiniciar();
		
};

#endif
