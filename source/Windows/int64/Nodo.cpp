#include "Nodo.h"

Nodo::Nodo(){
	this->dato=0;
	this->sig=NULL;
}
Nodo::Nodo(__int64 dato){
	this->dato=dato;
	this->sig=NULL;
}
