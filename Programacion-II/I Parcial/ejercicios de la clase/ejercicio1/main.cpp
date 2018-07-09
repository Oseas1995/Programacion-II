#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void ordenar(int * const,int &);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n=10;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	ordenar(A,n);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";	
	return 0;
}


void ordenar(int * const ptr, int &n){
	for(int pasada=1;pasada<n;pasada++){
		int t;
		for(int i=0;i<n-pasada;i++){
			if(ptr[i]>ptr[i+1]){
				t=ptr[i];
				ptr[i]=ptr[i+1];
				ptr[i+1]=t;
			}
			
		}
	}

}
