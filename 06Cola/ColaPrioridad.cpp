/*
Ejemplo de cola con prioridades
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//vamos con la estructura nodo

struct nodo{
	char dato;
	int prioridad;
	struct nodo * siguiente;
};


//estructura de la cola
struct cola{
	nodo *delante;
	nodo *atras;
};

//funcion para crear un nodo nuevo

struct nodo *crearNodo(char x, int pri){
	//vamos a crear ese nuevo nodo
	struct nodo *nuevoNodo = new (struct nodo);
	nuevoNodo->dato=x;
	nuevoNodo->prioridad=pri;
	return nuevoNodo;
}


void encolar(struct cola &q, char valor, int priori){
	//necesito mi auxiliar
	struct nodo *aux = crearNodo(valor, priori);
	aux->siguiente=NULL;
	
	if(q.delante == NULL){
		//es el primero en encolar
		q.delante=aux;
	}else{
		(q.atras)->siguiente = aux;
	}
	//siempre el aux debe apuntar al final
	q.atras = aux;
}


void mostrarCola(struct cola q){
	//auxliar
	struct nodo *aux;
	
	aux = q.delante;
	
	cout<<"\n Caracter de Prioridad\n";
	
	while(aux!=NULL){
		//hay datos
		cout<<" "<<aux->dato<<" | "<<aux->prioridad<<endl;
		aux = aux->siguiente;
	} 
}


void ordenarPrioridad(struct cola &q){
	//criterio de 0 como prioridad
	//el numero mayor es la mas alta
	
	struct nodo *aux1, *aux2;
	int p_aux;
	char c_aux;
	
	aux1 = q.delante;
	
	while(aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		while(aux2!=NULL){
			if(aux1->prioridad > aux2->prioridad){
				p_aux = aux1->prioridad;
				c_aux = aux1->dato;
				
				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;
				
				aux2->prioridad = p_aux;
				aux2->dato = c_aux;
			}
			aux2=aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}

void insertar(struct cola &q, char c, int pri){
	
	//encolar
	encolar(q, c, pri);
	
	//ordeno
	ordenarPrioridad(q);
	//nuevo comentario
}

void menu(){
	cout<<"\n Ejemplo de colas de prioridad\n";
	cout<<"1.- Encolar\n";
	cout<<"2.- Mostrar cola\n";
	cout<<"3.- Salir\n";
}

int main(){
	struct cola q;
	
	q.delante = NULL;
	q.atras = NULL;
	
	char c; //caracter del dato
	int priori; //prioridad
	int op; //opcion
	int x; //numero que devuelve para pop
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Ingrese un caracter: \n";
				cin>>c;
				cout<<"\n Ingrese su prioridad: \n";
				cin>>priori;
				
				insertar(q, c, priori);
				
				cout<<"\n Caracter: "<<c<<" encolado\n";
				break;
			case 2:
				cout<<"\n Mostrar elementos de la cola: \n";
				if(q.delante!=NULL){
					mostrarCola(q);
				}else{
					cout<<"\n La cola esta vacia\n";
				}
				break;
			default:
				cout<<"Ingrese una opcion valida\n";
				system("pause");
				exit(0);			
		}
		system("pause");
		system("cls");
	}while(op!=3);
	return 0;
}
