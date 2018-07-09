#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class vector{
	friend vector operator*(float , const vector&);
	private:
		int dim;
		float*elementos;
	public:
		vector();
		vector(int);
		~vector();
		void imprimir();
		float operator*(const vector&)const;
};


int main() {
	srand(time(0));
	//vector u;
	vector v(10);
	//u.imprimir();
	v.imprimir();
	vector z=2*v;
	z.imprimir();
	
	cout<<"v*z="<<v*z<<endl;
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

vector operator*(float k, const vector&u){
	vector v(u.dim);
	for(int i=0;i<v.dim;i++)
		v.elementos[i]=k*u.elementos[i];

return v;
}

float vector:: operator*(const vector&v)const{
	float s=0;
	for(int i=0;i<v.dim;i++)
		s+=elementos[i]*v.elementos[i];

return s;
}
