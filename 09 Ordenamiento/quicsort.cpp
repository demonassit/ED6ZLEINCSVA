/*
ejemplo de quicksort

necesito un programa que introduzca
n cantidad de elementos y los ordene

*/

#include <iostream>

using namespace std;

int array[] = {22, 55, 12, 1, 56, 89, 13, 17, 90, 9, 6, 2, 10};

//aplicamos media al array
const int micha = sizeof(array)/sizeof(int);

void intercambio(int i, int j){
	int t = array[j];
	array[j] = array[i];
	array[i] = t;
	return;
}

void imprimirarreglo(){
	cout<<"\n El arreglo : \n";
	for(int i = 0; i < micha; i++){
		cout<<" "<<array[i]<<" ";
	}
	return;
}

void particionar(int inicio, int fin){
	int i = inicio +1;
	int j = fin;
	
	if(fin <= inicio){
		return;
	}
	
	cout<<"\n A mimir wiii "<<inicio<<" := "<<array[i]<<" , "<<j<<" := "<<array[j]<<" \n";
	
	//ahora la operacion del pivote
	int pivote = array[inicio];
	
	cout<<"\n Pivote: "<<inicio<<" := "<<array[inicio];
	
	if(inicio + 1 == j){
		if(array[inicio] > array[j]) intercambio(inicio, j);
		return;
	}
	
	while(i < j){
		//recursivo
		while(pivote >= array[i] && micha -1)
		++i;
		while(pivote < array[j] && j > 0) 
		--j;
		
		if(i <j){
			intercambio(i, j);
		}else{
			intercambio(inicio, j);
		}
	}
	imprimirarreglo();
	
	particionar(inicio, j-1);
	particionar(i, fin);
}

void quicksort(){
	particionar(0, micha-1);
	return;
}

int main(){kkkkpkppp
	cout<<"\n Ejemplo de quicksort \n";
	quicksort();
	cout<<"\n Resultado final: \n";
	imprimirarreglo();
}

