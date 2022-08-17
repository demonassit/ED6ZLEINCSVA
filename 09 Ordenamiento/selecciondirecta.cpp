/*
ejemplo de seleccion directa 
metodo de ordenamiento
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	//declaramos un arreglo
	int vector[4] = {3, 2, 5, 8};
	
	//variables
	int i, j , k, aux;
	
	for(k = 0; k<=2; k++){
		i = k;
		aux = vector[k];
		for(j = k+1; j<=3; j++){
			if(vector[j] < aux){
				i = j;
				aux = vector[i];
			}
		}
		//intercambio
		vector[i] = vector[k];
		vector[k] = aux;
	}
	
	for(i = 0; i<=3; i++){
		cout<<" "<<vector[i]<<" ";
	}
}
