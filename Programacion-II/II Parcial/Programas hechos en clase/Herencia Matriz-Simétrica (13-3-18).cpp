#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class matriz{
	friend ostream&operator<<(ostream&,const matriz&);
	friend matriz operator-(const matriz&,const matriz&);
	protected:
		int n,m;
		float **elementos;
	public:
		
		matriz();
		matriz(int,int);
		~matriz();
		matriz operator+(const matriz&)const;
	
};

class simetrica:public matriz{
	friend ostream&operator<<(ostream&,const simetrica&);
	private:
	
	public:
		simetrica(int);
	simetrica operator+(const simetrica&)const;
};

int main(int argc, char** argv) {
	matriz A(3,3),B(3,3);
	cout<<"A=\n"<<A;
	cout<<"B=\n"<<B;
	cout<<"A+B=\n"<<A+B;
	//cout<<"A-B=\n"<<A-B;
	simetrica s(5),r(5);
	//cout<<"A.n="<<A.n;
	cout<<"s=\n"<<s;
	cout<<"r=\n"<<r;
	matriz &refs=s;
	matriz &refr=r;
	cout<<"s+r=\n"<<s+r;
	//cout<<"s.n="<<s.n;
	//cout<<"s-r=\n"<<s-r;
	
	
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



simetrica::simetrica(int dim){
	n=dim;
	m=dim;
	int temp;
	elementos=new float*[n];
	for(int i=0;i<n;i++)
		{elementos[i]=new float[n];
		for(int j=0;j<=i;j++)
			{temp=rand()%n;
			 elementos[i][j]=temp;
			elementos[j][i]=temp;
			}
		}
}

ostream&operator<<(ostream&escribir,const simetrica&A){
	escribir<<"********************************************\n";
	for(int i=0;i<A.n;i++)
		{for(int j=0;j<A.m;j++)
			escribir<<setw(4)<<A.elementos[i][j];
		escribir<<endl;
		}
return escribir;
}

simetrica simetrica::operator+(const simetrica&B)const{
if(n==B.n&&m==B.m){
	simetrica*c=new simetrica(n);//matriz c(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			c->elementos[i][j]=elementos[i][j]+B.elementos[i][j];
	
return *c;
}

else{
	simetrica c(n);
	return c;
}	
}

