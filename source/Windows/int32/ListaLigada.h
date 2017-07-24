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
		friend __int32 maxCarga();
		ListaLigada();
		~ListaLigada();
		void agregar (__int32);
		__int32 eliminar();
		bool vacia();
		__int32 valor();
		void reiniciar();
		
};

#endif
