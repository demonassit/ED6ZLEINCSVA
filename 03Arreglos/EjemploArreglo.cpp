//uso de arreglos en c++

#include <iostream>

using namespace std;

int main(){
	//declaracion de arreglos
	int numero[5] = {200, 150, 100, -50, 300} ;
	int suma;
	
	//quiero un programa que sume el contenido de un arreglo
	
	//definicion de valores
	/*numero[0] = 200;
	numero[1] = 150;
	numero[2] = 100;
	numero[3] = -50;
	numero[4] = 300;*/
	
	//suma = numero[0]+numero[1]+numero[2]+numero[3]+numero[4];
	
	suma = 0;
	
	for(int i=0; i<=4; i++){
		suma += numero[i];
		//suma = suma + numero[i]
	}
	
	cout<<"La suma es de: "<<suma;
	
	return 0;
}
