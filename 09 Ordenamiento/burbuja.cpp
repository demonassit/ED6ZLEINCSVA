/*
Ejemplo de burbuja
*/


#include <iostream>
#include <conio.h>
#include <string.h>

#define MAX 50

//un arreglo
struct ordenamiento{
	int elem;
};

using namespace std;
//metodos para burbuja

void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrar(int, struct ordenamiento[]);

int main(){
	int n;
	struct ordenamiento orden[MAX];
	
	cout<<"Ingrese el limite del arreglo:\n ";
	cin>>n;
	
	leerarray(n, orden);
	burbuja(n, orden);
	
	cout<<endl<<"El arreglo ordenano es: \n"<<endl;
	
	mostrar(n, orden);
	
	getch();
}

void leerarray(int n, struct ordenamiento a[]){
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el elemento: \n";
		cin>>a[i].elem;
	}
}

void burbuja(int n, struct ordenamiento a[]){
	int i, j;
	struct ordenamiento temp;
	
	//aqui aplico burbuja el intercambio del menor
	for(i = 1; i < n; i++){
		for(j = n-1; j>=i; j--){
			//comparacion
			if(a[j-1].elem > a[j].elem){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void mostrar(int n, struct ordenamiento a[]){
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i].elem;
	}
}

