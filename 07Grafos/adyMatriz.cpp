//ejemplo de grafo de matriz de adyacencia

#include <iostream>
#include <queue>  //cola
#include <stack>  //pila

using namespace std;

/*
vamos a crear un ejemplo usando objetos
y clases
*/

class Grafo{

private :
	int vertice, arista;
	int **adyMatriz;
	int *visitado;
	
public:
	//constructor
	Grafo(int ver, int arc) : vertice(ver), arista(arc){
		//la matriz generarla
		adyMatriz = new int * [ver];
		for(int i = 0; i < vertice; i++){
			adyMatriz[i] = new int[vertice];
			for(int j = 0; j < vertice; j++){
				adyMatriz[i][j] = 0;
			}
			
 		}
 		visitado = new int[vertice];
	}
	
	//visitados
	void visitados(){
		for(int i = 0; i < vertice; i++){
			visitado[i] = 0;
			cout<<visitado[i];
		}
	}
	
	//destructor
	~Grafo(){
		for(int i = 0; i < vertice; i++){
			delete[] adyMatriz[i];
		}
		delete[] adyMatriz;
	}
	
	void crear_grafo(){
		cout<<"Escribe los nodos y aristas \n";
		for(int i =0; i < vertice; i++){
			for(int j = 0; j < vertice; j++){
				cin>>adyMatriz[i][j];
			}
		}
	}
	
	void agregarArista(int i, int j){
		if(i>=0 && i<vertice && j>0 && j <vertice){
			adyMatriz[i][j] = 1;
		}
	}
	
	void removerArista(int i, int j){
		if(i>=0 && i<vertice && j>0 && j <vertice){
			adyMatriz[i][j] = 0;
		}
	}
	
	bool esArista(int i , int j){
		if(i>=0 && i<vertice && j>0 && j <vertice){
			return adyMatriz[i][j];
		}else{
			return false;
		}
	}
	
	//vamos a medir la profundidad
	void profundidad(int nodo){
		//si ya lo visite
		visitado[nodo] = 1;
		cout<<nodo<<"  ";
		for(int i = 0; i < vertice; i++){
			if(adyMatriz[nodo][i] && !visitado[i]){
				profundidad(i);
			}
		}
	}
	
	//vamos a medir la profundiad con base a una pila
	void profundidadI(int nodo){
		visitados();
		//inicializao mi pila
		stack<int> pila;
		pila.push(nodo);
		visitado[nodo] = 1;
		//mientras existan mas nodos que los agregue a 
		//la pila, si ya lo visito que lo saque
		while(!pila.empty()){
			int elemento = pila.top();
			pila.pop();
			cout<<elemento<<" ";
			//recorrer los demas nodos
			for(int i = 0; i < vertice; i++){
				if(adyMatriz[elemento][i]){
					//si lo visito?
					if(!visitado[i]){
						pila.push(i);
					}
					visitado[i] = 1;
				}
			}
		}
 	}
 	
 	//anchura
 	void anchura(int nodo){
 		visitados();
 		visitado[nodo] = 1;
 		//cola para su recorrido
 		queue<int> cola;
		cola.push(nodo);
 		while(!cola.empty()){
 			int elemento = cola.front();
 			cola.pop();
 			cout<<elemento<<"  ";
 			for(int i = 0; i <vertice; i++){
 				//saber si ya lo he visitado
				if(adyMatriz[elemento][i] && !visitado[i]){
					cola.push(i);
					visitado[i] = 1;	
				} 
				 
			 }
		 }
	 }
};	

int main(){
	int ver, arc;
	
	cout<<"Numero de vertices: \n";
	cin>>ver;
	cout<<"Numero de aristas: \n";
	cin>>arc;
	
	Grafo gh(ver, arc);
	cout<<"Creacion del grafo: \n";
	gh.crear_grafo();
	
	cout<<endl;
	
	cout<<"Busqueda en anchura: \n";
	gh.anchura(0);
	cout<<endl;
	cout<<"Busqueda en Profundidad: \n";
	gh.visitados();
	cout<<endl;
	gh.profundidad(0);
	cout<<endl;
	gh.profundidadI(0);
	cout<<endl;
}
	


