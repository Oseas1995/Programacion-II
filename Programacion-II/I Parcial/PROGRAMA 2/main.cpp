#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class vector{
	private:
		int dim;
		float*elementos;
	public:
		vector();
		vector(int);
		~vector();
		void imprimir();
};


int main() {
	srand(time(0));
	vector u;
	vector v(10);
	u.imprimir();
	v.imprimir();
	return 0;
}

vector::vector(){
	dim=3;
	elementos=new float[dim];
	elementos[0]=1;
	elementos[1]=1;
	elementos[2]=1;
}

vector::vector(int n){
	dim=n;
	elementos=new float[dim];
	
	for(int i=0;i<dim;i++)
		elementos[i]=rand()%100;
}

vector::~vector(){
	delete[]elementos;
}
void vector::imprimir(){
	cout<<"************************************\n";
	cout<<"(";
	for(int i=0;i<dim;i++)
		cout<<setw(4)<<elementos[i];
	
	cout<<")\n";
}
