#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

class vector{
	friend vector* operator+(const vector&,const vector&);
	friend vector operator*(float,const vector&);
	friend ostream& operator<<(ostream&,const vector&);
	
	private:
		int dim;
		float *elementos;
	public:
		vector();
		vector(int);
		~vector();
		float operator*(const vector&)const;
		vector* operator-(const vector&)const;
		double norma();
		
};

int main(int argc, char** argv) {
	srand(time(0));
	vector v;
	cout<<"Vector v: "<<v<<endl;
	vector v2(5);
	cout<<"Vector v2: "<<v2<<endl;
	vector v1;
	cout<<"Vector v1: "<<v1<<endl;
	cout<<"La norma del vector v es: "<<v.norma()<<endl;
	cout<<"La norma del vector v1 es: "<<v1.norma()<<endl;
	cout<<"La norma del vector v2 es: "<<v2.norma()<<endl;
	return 0;
}

//Constructor por defecto
vector::vector(){
	dim=3;
	elementos=new float[dim];
	elementos[0]=1;
	elementos[1]=1;
	elementos[2]=1;
}

//Constructor Alternativo
vector::vector(int n){
	dim=n;
	elementos=new float[dim];
	
	for(int i=0;i<dim;i++)
		elementos[i]=rand()%10;
	
}

//Destructor
vector::~vector(){
	delete[] elementos;
}

//Sobrecarga (<<)
ostream& operator<<(ostream& escribir, const vector&v){
	escribir<<"(";
	for(int i=0;i<v.dim;i++)
		escribir<<v.elementos[i]<<setw(4);
	cout<<")\n";
	
	return escribir;
}

//sobrecarga (+)
vector* operator+(const vector&v1, const vector&v2){
	if(v1.dim==v2.dim){
		vector *w=new vector(v1.dim);
		for(int i=0;i<w->dim;i++)
			w->elementos[i]=v1.elementos[i]+v2.elementos[i];
		return w;
	}
	else
		cout<<"Las dimensiones son distintas, NO SE PUEDEN SUMAR!!"<<endl;
		return NULL;	
}

//Sobrecarga (-)
vector* vector::operator-(const vector&v1)const{
	if(dim==v1.dim){
		vector *w=new vector(v1.dim);
		for(int i=0;i<w->dim;i++)
			w->elementos[i]=elementos[i]-v1.elementos[i];
		return w;
	}
	else
	    cout<<"Las dimensiones son distintas, NO SE PUEDEN RESTAR!!"<<endl;
		return NULL;	
}

//Multiplicacion por un escalar
vector operator*(float k, const vector&u){
	vector v(u.dim);
	for(int i=0;i<v.dim;i++)
		v.elementos[i]=k*u.elementos[i];

return v;
}

//multiplicacion
float vector:: operator*(const vector&v)const{
	float s=0;
	for(int i=0;i<v.dim;i++)
		s+=elementos[i]*v.elementos[i];

return s;
}

//Norma
double vector::norma(){
	double nor=0;
	for(int i=0;i<dim;i++){
		nor+=pow(elementos[i],2);
	}
	return sqrt(nor);
}

