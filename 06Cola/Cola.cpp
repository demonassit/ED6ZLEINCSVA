/*
Ejemplo de una cola
primeras entradas
primeras salidas

*/

#include <iostream>

using namespace std;

//definir la estructura base
struct nodo{
	int nro;
	struct nodo * siguiente;
};

//cola
struct cola{
	nodo *delante;
	nodo *atras;
};


//encolar
void encolar(struct cola &q, int valor){
	//auxiliar del nodo prar meterlo en la cola
	struct nodo * aux = new (struct nodo);
	
	aux->nro = valor;
	aux-> siguiente = NULL;
	
	if(q.delante == NULL){
		//es el primero en entrar
		q.delante = aux;
	}else{
		(q.atras)->siguiente = aux;
	}
	//el puntero debe de apuntar al ultimo
	q.atras = aux;
	
}

//desencolar
int desencolar(struct cola&q){
	int num;
	struct nodo *aux;
	
	//aux apunte al inicio de la cola
	aux = q.delante;
	num = aux->nro;
	q.delante = (q.delante)->siguiente;
	//liberes memoria del apuntador
	delete(aux);
	
	return num; 
}

void muestraCola(struct cola q){
	//necesitamos el auxiliar
	struct nodo *aux;
	//donde esta el inicio de lacola
	aux = q.delante;
	
	//si la cola esta vacia
	while(aux != NULL){
		cout<<" "<<aux->nro;
		aux = aux->siguiente;
	}
}

void vaciaCola(struct cola &q){
	//auxiliar
	struct nodo *aux;
	
	while(q.delante != NULL){
		aux = q.delante;
		q.delante = aux->siguiente;
		delete(aux);
	}
	q.delante = NULL;
	q.atras = NULL;
}

void menu(){
	cout<<"\n Ejemplo de una colita nwn\n";
	cout<<"1.- Encolar \n";
	cout<<"2.- Desencolar \n";
	cout<<"3.- Mostrar Cola \n";
	cout<<"4.- Vaciar Cola \n";
	cout<<"5.- Salir \n";
}

int main(){
	//defino la cola
	struct cola q;
	
	q.delante = NULL;
	q.atras = NULL;
	
	//variables
	int dato;
	int op;
	int x; //saber a quien eliminar
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Numero a encolar :\n";
				cin>>dato;
				encolar(q, dato);
				cout<<"\n Numero :"<<dato<<" encolado.\n";
				break;
			case 2:
				x = desencolar(q);
				cout<<"\n Numero : "<<x<< " Desencolado\n";
				break;
			case 3:
				cout<<"\Mostrando la colita :\n";
				if(q.delante!=NULL) muestraCola(q);
				else cout<<"\n Cola Vacia\n";
				break;
			case 4:
				vaciaCola(q);
				cout<<"\n Hecho, cola vacia";
				break;
		}
	}while(op!=5);
	return 0;
}


