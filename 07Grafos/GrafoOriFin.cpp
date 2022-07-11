/*
vamos a crear un grafo mediante el cual
se puedan ingresar el nodo y el camino
al que esta conectado
para calcular la busqueda de su anchura

*/

#include <stdio.h>
#include <queue>  //una colita

using namespace std;

#define MAX 500

//un vector para la matriz de adyacencia
vector<int> ady[MAX];
bool visitado[MAX];

void bfs(){
	//vamos a crear los elementos para
	//introducir coordenadas
	int ini, fin;
	
	printf("Nodo raiz \n");
	scanf("%d", &ini);
	printf("Nodo final \n");
	scanf("%d", &fin);
	
	//queremos una cola para almacenar los nodos
	queue<int> Q;
	
	Q.push(ini);
	
	//contar los pasos del recorrido
	int pasos = 0, maxi = 0;
	
	//mientras exista otro nodo
	//mientras la cola no este vacia
	
	while(!Q.empty()){
		//saber si la memoria de la cola esta en uso
		maxi = max(maxi, (int)Q.size());
		
		int actual = Q.front();
		
		Q.back();
		
		pasos++;
		
		if(actual == fin) break;
		
		//tengo que saber donde he estado
		visitado[actual] = true;
		//recorrer
		for(int i = 0; i <ady[actual].size(); ++i){
			//estamos viendo que nodos son adyacentes
			//al nodo que estoy visitando
			if(!visitado[ady[actual][i]]){
				//la i se refiere a la posicion en donde se encuentra el nodo
				printf("%d  -->  %d", actual, ady[actual][i]);
				//lo metemos a la cola
				Q.push(ady[actual][i]);
			}
		} 
	}
	
	printf("Memoria maxima : %d \n", maxi);
	printf("Numero de pasos que ha dado: %d \n", pasos);
	
}

int main(){
	//declaramos nuestras variables
	int V, E, x, y;
	
	printf("Ingrese el vertice inicial y vertice final\n");
	scanf("%d %d", &V, &E);
	
	//recorremos ini a fin
	for(int i = 1; i <= E; ++i){
		printf("Ingrese sus coordanadas de cada nodo: \n");
		scanf("%d %d", &x, &y);
		
	}
	bfs();
	
	return 0;
}
