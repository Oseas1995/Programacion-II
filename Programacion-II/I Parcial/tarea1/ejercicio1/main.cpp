#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void mostrarArreglo(int **,int,int);//Prototipo
void mostrarOrdenado(int **, int, int);
void ordenarAscendente(int **,int, int);

int main(int argc, char** argv) {
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior); GENERAR NUMEROS ALEATORIOS

	int n, **puntero, m;
	srand(time(NULL));
	cout<<"Ingrese el valor de N: ";
	cin>>n;
	/*cout<<"Ingrese el valor de m: ";
	cin>>m;*/

	m = 1 + rand()%11;//Numeros aleatorios del 0 al 10.

	puntero = new int*[n];//reservar memoria para las filas.
	for(int i=0;i<n;i++){

		puntero[i] = new int[m];//reservar memoria para las columnas.
	}


	cout<<"\nElementos de la matriz "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"elemento["<<i<<"]["<<j<<"]: ";
			puntero[i][j] = rand()%10;//numeros aleatorios del 0 al 9.
			cout<<puntero[i][j]<<endl;
		}
		cout<<"\n";
	}

	mostrarArreglo(puntero, n, m);

	ordenarAscendente(puntero, n, m);

	mostrarOrdenado(puntero, n, m);


	//Liberar memoria dinamica.
	for(int i=0;i<n;i++){
		delete[] puntero[i];
	}
	delete[] puntero;

	return 0;
}


void mostrarArreglo(int **puntero, int n, int m){
	cout<<"imprimiendo arreglo:\n\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<puntero[i][j]<<" ";
		}
		cout<<"\n";
	}
}


void mostrarOrdenado(int **puntero, int n, int m){
	cout<<"\n\nimprimiendo arreglo ascendente:\n\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<puntero[i][j]<<" ";
			}
			cout<<"\n";
		}

}


void ordenarAscendente(int **puntero,int n, int m){
	for(int i=0;i<n;i++){
		int aux;
		int j;
		for(j=0;j<m-1;j++){
			if(puntero[i][j] > puntero[i][j+1]){
				aux = puntero[i][j];
				puntero[i][j] = puntero[i][j+1];
				puntero[i][j+1] = aux;
			}
		}
	}
}
