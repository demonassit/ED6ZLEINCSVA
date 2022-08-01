/*
arbol binario de busqueda

*/

#include <stdio.h>
#include <stdlib.h>
#include <cctype>


//vamos a definri un templete para manejo de errores

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//definimo con el nodo para el arbol
struct Nodo{
	int dato;
	Nodo *padre;
	Nodo *izq;
	Nodo *der;
};

void insertar(Nodo *&arbol, const int n, Nodo *padre);
void mostrar(Nodo *arbol, int espaciado);
void preOrder(Nodo *arbol);
void inOrder(Nodo *arbol);
void postOrder(Nodo *arbol);
bool esUnNumero(const char* cadena);
bool seguirIngresando();
char mainMenu();
int pedirNumero();

int main(){
	char op = '0';
	Nodo *arbol = NULL;
	
	do{
		system("CLS");
		if(arbol){
			printf("\n ******** Ejemplo de Arboo ABB *****\n");
			mostrar(arbol, 0);
			printf("\n **** Fin del Arbol ABB **** \n");
			
		}
		switch(op = mainMenu()){
			case '1':
				insertar(arbol, pedirNumero(), NULL);
				break;
			case '2':
				//preorder
				printf("\n Recorrido Preorder: \n");
				preOrder(arbol);
				printf("\n Fin de preorder n");
				break;
			case '3':
				//inorder
				printf("\n Recorrido Inorder: \n");
				inOrder(arbol);
				printf("\n Fin de inorder n");
				break;
			case '4':
				//postorder
				printf("\n Recorrido Postorder: \n");
				postOrder(arbol);
				printf("\n Fin de postorder n");
				break;
		}
		printf("\n");
		system("PAUSE");
	}while(op != '0');
	return 0;
}


char mainMenu(){
	char temp = '0';
	
	printf("\n Programa de ejemplo de un arbol ABB \n");
	printf("\n 1.- Insertar \n");
	printf("\n 2.- Leer en Preorder \n");
	printf("\n 3.- Leer en Inorder \n");
	printf("\n 4.- Leer en Postorder \n");
	printf("\n 0.- Salir \n");
	scanf("%c", &temp);
	return temp;
	
}

bool seguirIngresando(){
	//metodo par aseguir ingresando valores al arbol
	char temp = '0';
	do{
		printf("\n Desea seguir ingresando valores al Arbol (Y/N)\n");
		scanf("%c", &temp);
		switch(temp){
			case 'Y':
				return true;
			case 'N':
				return false;
		}
	}while(temp != 'Y' || temp != 'N');
}

bool esUnNumero(const char *cadena){
	for(; *cadena; ++cadena){
		if(!std:: isdigit(*cadena))
		return false;
	}
	return true;
}

int pedirNumero(){
	char temp[255];
	
	do{
		printf("\n Ingrese el numero: \n");
		scanf("%s", temp);
		
	}while(!esUnNumero(temp));
	//regresa de una cadea un int
	return atoi(temp);
}
//isnertar

void insertar(Nodo *&arbol, const int n, Nodo *padre){
	if(!arbol){
		Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo -> dato = n;
		nuevo -> padre = padre;
		nuevo -> izq = NULL;
		nuevo -> der = NULL;
		arbol = nuevo;
	}else{
		//ocndicion del arbol bin
		if(n < arbol -> dato){
			insertar(arbol->izq, n, arbol);
			
		}else{
			insertar(arbol->der, n, arbol);
		}
	}
}

void mostrar(Nodo *arbol, int espaciado){
	if(!arbol){
		return;
	}else{
		mostrar(arbol->der, espaciado+1);
		//recorrer
		for(int i = 0; i < espaciado; i++){
			printf("      ");
		}
		printf("    %d \n", arbol->dato);
		mostrar(arbol->izq, espaciado+1);
	}
}

//preorder
void preOrder(Nodo *arbol){
	if(!arbol){
		return;
	}else{
		printf("    %d", arbol->dato);
		preOrder(arbol->izq);
		preOrder(arbol->der);
	}
}

//inorder
void inOrder(Nodo *arbol){
	if(!arbol){
		return;
	}else{
		
		inOrder(arbol->izq);
		printf("    %d", arbol->dato);
		inOrder(arbol->der);
	}
}

//postorder
void postOrder(Nodo *arbol){
	if(!arbol){
		return;
	}else{
		
		postOrder(arbol->izq);
		postOrder(arbol->der);
		printf("    %d", arbol->dato);
		
	}
}
