#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class matriz{
	friend ostream&operator<<(ostream&,const matriz&);
	friend matriz operator-(const matriz&,const matriz&);
	private:
		float **elementos;
	protected:
		int n,m;//n: # filas, m: # columnas
		
	public:
		
		matriz();
		matriz(int,int);
		~matriz();
		matriz operator+(const matriz&)const;
	
};

class tridiagonal:public matriz{
	friend ostream&operator<<(ostream&,const tridiagonal&);
	private:
	float *diag;
	float*diagsup;
	float*diaginf;
	public:
	tridiagonal();
	tridiagonal(int);
	~tridiagonal();
};

int main(int argc, char** argv) {
	matriz A(3,3),B(3,3);
	cout<<"A=\n"<<A;
	cout<<"B=\n"<<B;
	cout<<"A+B=\n"<<A+B;
	tridiagonal T(5);
	cout<<T;
	return 0;
}


matriz::matriz(){
	n=2;
	m=2;
	elementos=new float*[n];
	for(int i=0;i<n;i++)
		elementos[i]=new float[m];
	
	elementos[0][0]=1;
	elementos[0][1]=0;
	elementos[1][0]=0;
	elementos[1][1]=1;	
		
}

matriz::matriz(int filas,int columnas){
	n=filas;
	m=columnas;
	elementos=new float*[n];
	for(int i=0;i<n;i++)
		elementos[i]=new float[m];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			elementos[i][j]=rand()%100;
		
}

matriz::~matriz(){
	for(int i=0;i<n;i++)
		delete[]elementos[i];
		
	delete[]elementos;
}

ostream&operator<<(ostream&escribir,const matriz&A){
	escribir<<"********************************************\n";
	for(int i=0;i<A.n;i++)
		{for(int j=0;j<A.m;j++)
			escribir<<setw(4)<<A.elementos[i][j];
		escribir<<endl;
		}
return escribir;
}

matriz matriz::operator+(const matriz&B)const{

cout<<"ESTAMOS EN LA SUMA DE LA CLASE MATRIZ\n\n;";
if(n==B.n&&m==B.m){
	matriz*c=new matriz(n,m);//matriz c(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			c->elementos[i][j]=elementos[i][j]+B.elementos[i][j];
	
return *c;
}

else{
	matriz c;
	return c;
}	
}


matriz operator-(const matriz&A,const matriz&B){
if(A.n==B.n&&A.m==B.m){
	matriz*c=new matriz(A.n,A.m);//matriz c(n,m);
	for(int i=0;i<A.n;i++)
		for(int j=0;j<A.m;j++)
			c->elementos[i][j]=A.elementos[i][j]-B.elementos[i][j];
	
return *c;
}

else{
	matriz c;
	return c;
}	
}

tridiagonal::tridiagonal(){
	n=3;
	m=3;
	diag=new float[n];
	diagsup=new float[n-1];
	diaginf=new float[n-1];
	for(int i=0;i<n-1;i++){
		diag[i]=1;
		diagsup[i]=1;
		diaginf[i]=1;
	}
	
	diag[n-1]=1;
}

tridiagonal::tridiagonal(int dim){
	n=dim;
	m=dim;
	diag=new float[n];
	diagsup=new float[n-1];
	diaginf=new float[n-1];
	for(int i=0;i<n-1;i++){
		diag[i]=rand()%10;
		diagsup[i]=rand()%10;
		diaginf[i]=rand()%10;
	}
	
	diag[n-1]=rand()%10;
}

tridiagonal::~tridiagonal(){
delete[]diag;
delete[]diagsup;
delete[]diaginf;	
}

ostream&operator<<(ostream&escribir,const tridiagonal&T){
for(int i=0;i<T.n;i++)
{for(int j=0;j<T.n;j++)
if(i-j==0)
	escribir<<setw(3)<<T.diag[i];
else
	if(i-j==1)
		escribir<<setw(3)<<T.diaginf[j];
	else
		if(i-j==-1)
			escribir<<setw(3)<<T.diagsup[i];
		else
			escribir<<setw(3)<<0;
escribir<<endl;
}
}
