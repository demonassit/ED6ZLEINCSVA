/*
vamos a suponer que vamos a
tener el siguiente grafo

5 3
1 2
2 3
4 5

correspondiente direccion de la
arista

*/


#include<stdio.h>
#include<vector>
#include<cstring>
//sirve para poder hacer operaciones
//con cadenas para manipular
//los caracteres de la matriz

using namespace std;

//definir un tamaño para el vector de 
//memoria

#define MAX 10001

vector<int> ady[MAX];

/*
tenemos que tener una variable que
detecte el recorrido para saber
si ya visito el nodo

se encargue de saber el nodo

*/

bool visitado[MAX]; //el camino o arista

bool visitado_componente[MAX]; //nodo

//algoritmo de recorrido + corto

void dfs(int u){
	//saber si ya visitaste el camino o arista
	visitado[u] = true;
	//saber si ya visite el nodo
	visitado_componente[u] = true;
	for(int v = 0; v<ady[u].size(); v++){
		if(!visitado[ady[u][v]]){
			dfs(ady[u][v]);
		}
	}
}

int main(){
	//variables para el grafo
	int V, E, u, v;
	
	//obtengo los elementos a la memoria
	scanf("%d, %d", &V, &E);
	
	//creo el ciclo que se encarga
	//de meter, sacar, entrar y 
	//salir del nodo
	
	while(E--){
		printf("Ingresa el nodo y su arista: \n");
		scanf("%d, %d", &u, &v);
		ady[u].push_back(v);
		ady[u].push_back(u);
	}
	
	printf("Cantidad de nodos conexos: \n");
	int total = 0;
	
	/*
	hay que saber todos los caminos del nodo, y su peso
	correspondiente, para ello necesitamos obtener
	el camino, el inicio y su tamaño o peso
	*/
	
	//vamos a ocupar una funcion propia del grafo
	memset(visitado, 0, sizeof(visitado));
	//meter en un ciclo para saber todos los posibles
	//caminos de los nodos
	for(int i = 1; i<= V; ++i){
		if(!visitado[i]){
			memset(visitado_componente, 0, sizeof(visitado_componente));
			dfs(i);
			printf("Componente : %d", total+1);
			//recorrer los valores del componente
			for(int j = 1; j<=V; ++j){
				if(!visitado_componente[j]){
					printf(" %d ", j);
				}
			}
			printf("\n");
			total++;
		}
	}
	printf("%d \n", total);
	return 0;
}

