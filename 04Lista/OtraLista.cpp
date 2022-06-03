//lista con apuntadores

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>

/*
stdio es la libreria standar de ++
para el manejo de entradas y salidas en consola

stdlib es la libreria standar de estructuras 
de datos en c++ ára listas, pilas, colas, arboles
grafos

conio es la libreria standar para el manejo de 
manipulacion de la pantalla, pausar, colores,
manipulacion de ventanas
*/

using namespace std;

//la definicion de la lista

struct dato{
	int i;
	dato *s;//nodo siguiente
}*a, *i, *p, *e;

//metodos

int buscar(int d);
void insertar(void);
void mostrar(void);
void borrar(void);
void menu(void);
//void guardar(void);
//void cargar(void);

//principal
main(){
	menu();
}

//menu

void menu(void){
	int opc, da;
	do{
		//imprimir le menu
		cout<<"Ejemplo de una lista con apuntadores";
		cout<<"\n 1.- Buscar datos:";
		cout<<"\n 2.- Insertar datos:";
		cout<<"\n 3.- Motrar datos:";
		cout<<"\n 4.- Borrar dato:";
		cout<<"\n 5.- Guardar datos en un archivo:";
		cout<<"\n 6.- Cargar datos en un archivo:";
		cout<<"\n 7.- Salir";
		cout<<"\n Seleccione la opcion deseada.";
		cin>>opc;
		
		switch(opc){
			case 1:
				//buscar
				cout<<"\n Ingresa el dato a buscar: ";
				cin>>da;
				if(buscar(da)){
					cout<<"Datos si existe wiiii";
				}else{
					cout<<"Dato no existe solo juguito contigo T_T";
					getch(); //pausa
				}
				break;
				
			case 2:
				//ingresar
				cout<<"\n Ingresa el dato:";
				cin>>da;
				insertar(da);
				break;
			
			case 3:
				//mostrar
				mostrar();
				break;
				
			case 4:
				//borrar
				borrar();
				break;
				
			case 5:
				//guardar
				//guardar();
				break;
				
			case 6: 
				//cargar
				//cargar();
				break;
			
			case 7: 
				//salir
				cout<<"\n Ayos, gracias uwu";
				getch;
				//antes de salir del programa
				//hay que borrar todos los datos
				//de la lista
				p = i;
				while(p){
					a = p;
					p = p->s;
					delete(a);	
				}
				//salir
				exit(0);
				
			default:
				cout<<"Aprenda a leer, opcion no valida";
				getch();
				
				
		}
	}while(opc);
}


//mostrar

void mostrar(void){
	int cont = 1;
	//saber si hay una lista
	if(!i){
		cout<<"No hay lista parar mostrar";
		getch();
		return;
	}
	p = i;
	cout<<"\n\n";
	/*
	Como si existe un datos para la lista
	tenermos que empezar a recorrerarla
	por cada uno de los elementos
	*/
	while(p){
		cout<<cont++<<"\nValor : "<<p->i<<enld;
		p = p -> s;
	}
	cout<<"\n Fin de la lista";
	getch();
}

//buscar
int buscar(int d){
	//saber si hay una lista
	if(!i){
		cout<<"No hay datos en la lista parar mostrar";
		getch();
		return;
	}
	
	//si hay
	p = i;
	a = NULL;
	
	while(p->s && p->i < d){
		//recorrer los valores de la lista
		a = p;
		p = p->s;
	}
	
	return (p->i == d?1:0);
}

/*
para insertar cuantos caminos hay?
1.- la primera vez que se crea un dato

se debe de crear el nodo y verificar los apuntadores

2.- enmedio

se debe de buscar donde se va a ingresar
debe de acomodar el apuntador anterior
y el apuntador siguiente (apuntador que apunta)

3.- final solo se inserta y se ajusta el apuntador




*/

void insertar(int dat){
	
	//saber si esta vacia
	if(!i){
		//es la primer avez que se mete un dato
		i = new (dato);
		i->s = NULL;
		i->i = dat;
		return;
	}
	if(buscar(dat)){
		//porque si existe el dato
		cout<<"\n El dato existe T_T";
		getch();
		return;
		
	}
	
	/*
	supongamos que tenemos lo siguiente
	
	nodo1 = -3, nodo2 = 0, nodo3 = 5
	
	insertar 3
	*/
	
	e = new (dato);
	
	e->i = dat;
	
	if(p==i && p->s){
		//primero hago la comparacion
		if(p->i < e->i){
			//final
			p->s = e;
			e->s = NULL;
		}else{
			e->s = p;
			i=e;
		}
		return;
	}
	if(p->s){
		a->s = e;
		e->s = p;
		return;
	}
	if(e->i > p->i){
		e->s = NULL;
		p->s = e;
	}else{
		a->s = e;
		e->s = p;
	}
}

//borrar

void borrar(void){
	cout<<"\n Ingresa el dato que quieres borrar: ";
	cin>>da;
	if(buscar(da)){
		if(a){
			a->s = p->s;
		}else{
			i=p->s;
		}
		delete(p);
		cout<<"\n Dato eliminado";
	}else{
		cout<<"\n Dato no encontrado T_T";
		getch();
	}
}





