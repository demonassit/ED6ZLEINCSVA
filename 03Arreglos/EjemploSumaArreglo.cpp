#include <iostream>

using namespace std;

int main(){
	float vector1[3];
	float vector2[3];
	float vectorSuma[3];
	int i;
	
	//vamos a llenar los valores de los vectores
	for(i=0; i<3; i++){
		cout<<"Introduce el valor "<<i<<" del primer vector";
		cin>>vector1[i];
	}
	for(i=0; i<3; i++){
		cout<<"Introduce el valor "<<i<<" del segundo vector";
		cin>>vector2[i];
	}
	
	//calculamos la suma
	for(i=0; i<3; i++){
		vectorSuma[i] = vector1[i] + vector2[i]; 
	}
	
	cout<<"El vector suma es de: \n";
	for(i=0; i<3; i++){
		cout<<vectorSuma[i]<<" ";
	}
	
	return 0;
	
}
