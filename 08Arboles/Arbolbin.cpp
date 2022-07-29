//ejemplo de un arbol

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//vamos a crear la estructura base de un arbol bin

struct nodo{
	//el dato
	char dato;
	//nodo der
	struct nodo *der;
	//nodo izq 
	struct nodo *izq;
};

//ahroa vamoa  poder operar las ramas
typedef struct nodo _nodo;

//vamos a crear una definicion de como va a operar
//cada una de las ramas izq y der

_nodo *crear(char dato){
	//delcaro mi nodo
	_nodo *nuevo;
	//vamos a ocupar sizeof para solicitar el tamaño
	//de la estructura del arbol
	nuevo = (_nodo *)malloc(sizeof(_nodo));
	nuevo -> dato = dato;
	nuevo -> der = NULL;
	nuevo -> izq = NULL;
	return nuevo;
}

//metodo para agregar a la derecha
_nodo *agregarDerecha(_nodo *nuevo, _nodo *raiz){
	raiz -> der = nuevo;
	return raiz;
}

//metodo para agregar a la izq
_nodo *agregarIzquierda(_nodo *nuevo, _nodo *raiz){
	raiz -> izq = nuevo;
	return raiz;
}

//vamos a imprimir el arbol

void imprimir(_nodo *nodo){
	//tenemos que saber si el nodo esta vacio
	if(nodo != NULL){
		printf(" %c ", nodo->dato);
	}
}

//recorridos 

//preorden
void preOrden(_nodo *raiz){
	//nodo actual, rama izq, rama der
	if(raiz!=NULL){
		imprimir(raiz);
		//recursividad
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

//inorden
void inOrden(_nodo *raiz){
	//nodo izq, raiz, rama der
	if(raiz!=NULL){		
		//recursividad
		inOrden(raiz->izq);
		imprimir(raiz);
		inOrden(raiz->der);
	}
}

//postorden
void postOrden(_nodo *raiz){
	//nodo izq, der, raiz
	if(raiz!=NULL){		
		//recursividad
		postOrden(raiz->izq);
		postOrden(raiz->der);
		imprimir(raiz);
	}
}


int main(){
	_nodo *raiz;
	
	raiz = crear('+');
	
	raiz -> izq = crear('*');
	raiz -> der = crear('=');
	
	raiz -> izq -> izq = crear('A');
	raiz -> izq -> der = crear('B');
	
	raiz -> der -> izq = crear('/');
	
	raiz -> der -> izq -> izq = crear('C');
	raiz -> der -> izq -> der = crear('D');
	
	raiz -> der -> der = crear('2');
	
	//vamos a imprimir el arbolito
	printf("\n Preorden (RID): \n");
	preOrden(raiz);
	
	printf("\n Inorden (IRD): \n");
	inOrden(raiz);
	
	printf("\n Postorden (IDR): \n");
	postOrden(raiz);
	
	printf("\n");
	
	return 0;
}
