#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdio>
#include <cstdint>
#include "ListaLigada.h"
#include "Bloqueador.h"
#include <thread>

using namespace std;

ListaLigada* primos;
int encontrar;
int encontrados=0;
int nthreads;
int nthread=0;
int64_t u;
Bloqueador semaforo1;
Bloqueador semaforo2;

int maximo(int64_t numero){
    return (int64_t) ceil(sqrt(numero));
}
void run(){
	semaforo1.lock();
	int id=nthread;
	nthread++;
	semaforo1.unlock();
	Nodo *t;
    int64_t m;
    bool primo;
	int64_t comprobar;
	while(encontrados<encontrar){
		semaforo1.lock();
		comprobar=u;
		u+=2;
		semaforo1.unlock();
		primo=true;
		m = maximo(comprobar);
		for(int i=0;i<nthreads;i++){
			t =primos[i].head;
	        while(t!=NULL&&t->dato<=m){
	            if(comprobar%t->dato==0){
	                primo=false;
	                break;
	            }
	        	t=t->sig;
	        }
	        if(!primo)break;
    	}
		t=NULL;
        if(primo){
        	semaforo2.lock();
            encontrados++;
            semaforo2.unlock();
			primos[id].agregar(comprobar);
        }
	}
}
int64_t maxCarga(){
	int64_t max=0;
	for(int i=0;i<nthreads;i++){
		if(primos[i].tail!=NULL){
			if(primos[i].tail->dato>max){
				max=primos[i].tail->dato;
			}
		}
	}
	return max;
}
int cargar(string fichero){
    primos = new ListaLigada[nthreads];
	ifstream file;
   	string s;
    int n=0;
	file.open(fichero.c_str());
    if(file.is_open()){
    	while(!file.eof()){
    		getline(file,s);
    		if(s.length()>=1){
				primos[0].agregar(atoi(s.c_str()));
				n++;
			}
		}
	}
	else{
		primos[0].agregar(2);
		primos[0].agregar(3);
		primos[0].agregar(5);
		n=3;
	}
	u = maxCarga()+2;
	cout<<"Carga Completa"<<endl;
	return n;
}
bool estaVacia(){
	for(int i=0;i<nthreads;i++){
		if(!primos[i].vacia()) return false;
	}
	return true;
}
void guardar(string salida){
	stringstream ss;
	int64_t min;
	int pos;
	while(!estaVacia()){
		min= 9223372036854775807;
		pos=-1;
		for(int i=0;i<nthreads;i++){
			if(primos[i].head!=NULL&&primos[i].head->dato<min){
				min=primos[i].head->dato;
				pos=i;
			}
		}
		ss<<primos[pos].eliminar()<<std::endl;
	}
	ofstream fichero;
	salida+=".txt";
	fichero.open(salida.c_str(),std::ios::trunc);
	fichero<<ss.str();
	fichero.close();

}
string tiempo(float segundos){
	float m=0,h=0,d=0;
	if(segundos>86400){
		float r = fmod(segundos,86400);
		d=(segundos-r)/86400;
			segundos-=(d*86400);
	}
	if(segundos>3600){
		float r = fmod(segundos,3600);
		h=(segundos-r)/3600;
		segundos-=(h*3600);
	}
	if(segundos>60){
		float r = fmod(segundos,60);
		m=(segundos-r)/60;
		segundos-=(m*60);
	}
	stringstream ss;
	if(d>0){
		if(d>1)ss<<d<<" Dias ";
		else ss<<d<<" Dia ";
	}
	if(h>0){
		if(h>1)ss<<h<<"  Horas ";
		else ss<<h<<"  Hora ";
	}
	if(m>0){
		if(m>1)ss<<m<<"  Minutos ";
		else ss<<m<<"  Minuto ";
	}
	if(segundos>0){
		if(segundos>1)ss<<segundos<<"  Segundos ";
		else ss<<segundos<<"  Segundo ";
	}
	return ss.str();
}
int main() {
	nthreads = std::thread::hardware_concurrency();
    string nombre,entrada;
    cout<<"Cuantos numeros primos desea encontrar?: ";
    cin>>encontrar;
    cout<<"Ingrese el nombre del fichero de salida: ";
    cin>>nombre;
    cout<<"Ingrese el nombre del fichero de entrada: ";
	cin>>entrada;
	encontrados=cargar(entrada);
	cout<<"Numero de Hilos: "<<nthreads<<endl;
	cout<<"Busqueda Iniciada"<<endl;
	clock_t busquedai = clock();
	thread* threadlist = new thread[nthreads];
	for(int i=0;i<nthreads;i++){
		threadlist[i] = thread(run);
	}
	for(int i = 0;i < nthreads;i++) {
		threadlist[i].join();
	}
	clock_t busquedaf = clock();
	cout<<"Busqueda Terminada"<<endl;
	cout<<"Iniciando Guardado"<<endl;
	clock_t guardari = clock();
	guardar(nombre);
	clock_t guardarf = clock();
	cout<<"Guardado Terminado"<<endl;
	cout<<"Tiempo Busqueda Primos: "<<tiempo((busquedaf - busquedai) / (float)CLOCKS_PER_SEC)<<endl;
    cout<<"Tiempo Guardado Primos: "<<tiempo((guardarf - guardari) / (float)CLOCKS_PER_SEC)<<endl;
    cout<<"Tiempo Total: "<<tiempo((guardarf - busquedai) / (float)CLOCKS_PER_SEC)<<endl;
    cout << "Presione ENTER para Salir: ";
    cin.ignore().get();
}
