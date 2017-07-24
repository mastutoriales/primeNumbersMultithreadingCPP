#include "ListaLigada.h"

ListaLigada::ListaLigada(){
    head=NULL;
    tail=NULL;
    pos=NULL;
}
void ListaLigada::agregar(int dato){
    Nodo* t = new Nodo(dato);
	if(head!=NULL){
        tail->sig=t;
        tail=t;
    }
    else{
        head=t;
        tail=t;
    }
}
int ListaLigada::eliminar(){
    if(head!=NULL){
        int d = head->dato;
        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
            Nodo* t= head;
            head=head->sig;
            delete t;
        }
        return d;
    }
    else{
        return 0;
    }
}
bool ListaLigada::vacia(){
    return (head==NULL);
}
ListaLigada::~ListaLigada(){
	while(!vacia()){
		eliminar();
	}
}
int ListaLigada::valor(){
	if(pos==NULL||head==NULL){
		return 0;
	}
	else{
		t = pos;
		pos=pos->sig;
		return t->dato;
	}
}
void ListaLigada::reiniciar(){
	pos=head;
}
