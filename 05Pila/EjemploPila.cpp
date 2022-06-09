/*
Vamos a crear un ejemplo de una 
pila simple, porque quiero que hagan 
torres de hanoi



*/


#include <iostream>
#include <stdlib.h>

using namespace std;

//ejemplo de una pila
struct Nodo{
	int valor;
	Nodo *siguiente;
};

//metodos
void insertarPila(Nodo *&, int);
void mostrarPila(Nodo *&);
void eliminarPila(Nodo *&, int &);

int main(){
	/*
	El primero en entrar es el ultimo
	en salir, el ultimo que entra
	es el primero que sale
	*/
	int cantidad, i=0, op=1, v;
	
	//declaro la pila
	Nodo *pila = NULL;
	//menu
	while(op!=4){
		cout<<"Selecciona la opcion deseada: \n";
		cout<<"1.- Insertar valor:\n ";
		cout<<"2.- Mostrar valores:\n ";
		cout<<"3.- Eliminar valor:\n ";
		cout<<"4.- Salir:\n ";
		cin>>op;
		
		switch(op){
			case 1:
				cout<<"Ingresa la cantidad de valores a insertar en la pila:\n";
				cin>>cantidad;
				
				while(i<cantidad){
					cout<<"Ingresa el valor: \n";
					cin>>v;
					insertarPila(pila, v);
					i++;
				}
				break;
				
			case 2:
				mostrarPila(pila);
				break;
			
			case 3: 
				//saber si esta vacia
				if(pila == NULL){
					cout<<"No se puede eliminar, pila vacia.\n";
				}else{
					cout<<"Se elimina el valor\n";
					while(pila!=NULL){
						//hay valores
						eliminarPila(pila, v);
						if(pila!=NULL){
							cout<<v<<" | "<<endl;
						}else{
							cout<<" * "<<endl;
						}
					}
					
				}
				break;
			default:
				cout<<"La opcion no existe\n";
									
		}
	}
	return 0;
	
}


//push
void insertarPila(Nodo *&pila, int v){
	//crear el nodo
	Nodo *pushpila = new Nodo();
	pushpila -> valor = v;
	pushpila->siguiente = pila;
	pila=pushpila;
}

//mostrar
void mostrarPila(Nodo *&pila){
	//necesito un auxiliar para mostrar
	//los valores
	Nodo *aux;
	if(pila==NULL){
		cout<<"No hay datos en la pila, esta vacia\n ";
	}else{
		aux = pila;
		while(aux!=NULL){
			cout<<"Valor: "<<aux->valor<<endl;
			aux=aux->siguiente;
		}
	}
}


//pop
void eliminarPila(Nodo *&pila, int &v){
	Nodo * aux = pila;
	v = aux->valor;
	pila = aux->siguiente;
	delete aux;
}













