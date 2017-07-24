#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "Nodo.h"
#include <cstdlib>
#include <iostream>
#include <cstdint>

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
		friend int maxCarga();
		ListaLigada();
		~ListaLigada();
		void agregar (int);
		int eliminar();
		bool vacia();
		int valor();
		void reiniciar();
		
};

#endif
