#include "Nodo.h"

Nodo::Nodo(){
	this->dato=0;
	this->sig=NULL;
}
Nodo::Nodo(__int32 dato){
	this->dato=dato;
	this->sig=NULL;
}
