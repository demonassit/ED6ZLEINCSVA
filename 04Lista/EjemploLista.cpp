/*
Una lista es una estructura de datos que deriva
una secuancia conectada con nodos y cada yno de los
cuales cintiene un dato
Hay un nodo al comienzo llamado la cabeza o frente
Hay un nodo del termino llamado cola o atras

La lista solo puede ser recorrida en secuencia de
atras o hacia adelante

Operaciones de su propia estructura

añadir o insertar elemento
mover atraves de la lista de pri a fin
buscar elementos

Apuntadores

& memoria
* al dato
-> asigna

ejemplo

Nodo *elemento -> &elemento -> valor

en c++ vamso a ocupar list ya que es una clase
de tipo templete nos permite crear listas
que contengan cualquier tipo de objeto

la operaciones que se pueden incluir en la lista son:

push meter
pop sacar

begin()
end()

size()
empty()




*/



#include<iostream>

using namespace std;

//definir la estructura de la lista
struct Nodo{
	//los valores de la lista
	int valor;
	Nodo *siguiente;
};


//definri los metodos 
void insertarLista(Nodo *&, int);

int main(){
	//declarar mi variable de la lista
	//que apunte a null
	Nodo *lista = NULL;
	
	//variables
	int op = 1, c, i=0, valores;
	
	cout<<"Trabajando con listas(simples, doblemente enlazadas, circulares y circulares dobles)"<<endl;
	while(op!=3){
		cout<<"Ejemplo de lista simple: "<<endl;
		cout<<"1.- Insertar nuevo valor "<<endl;
		cout<<"2.- Ver la lista "<<endl;
		cout<<"3.- Salir "<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Indica el numero de valores a introducir\n";
				cin>>valores;
				while(i<valores){
					cout<<"Valor["<<i<<"]\n";
					cin>>c;
					//insertar el valor
					insertarLista(lista, c);
					i++;
				}
				break;
			case 2:
				cout<<"Mostrar los valores de la lista\n";
				cout<<"imprimir valores";
				break;
			default:
				cout<<"Gracias por mimir aqui uwu";
		}
	}
	return 0;
}

void insertarLista(Nodo *&lista, int c){
	//crear una nueva lista
	Nodo *inslista = new Nodo();
	//debo de asignar el valor de la lista
	inslista->valor = c;
	
	//necesitar un auxiliar para encadenar los valores de la lista
	Nodo *aux = lista;
	Nodo *aux2;
	//meter los valores de forma ordenada 
	while((aux!=NULL) && (aux->valor < c)){
		aux2 = aux;
		aux = aux->siguiente;
	}
	if(inslista==aux){
		lista = inslista;
	}else{
		aux2->siguiente = inslista;
	}
	
	inslista -> siguiente = aux;
	
	cout<<"Elemento "<<c<<" insertado"<<endl;
}







