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
		virtual matriz*suma(const matriz&)const;
	virtual void f1(matriz&B){
		cout<<"ESTAMOS EN LA CLASE MATRIZ\n";
	}
};

class simetrica:public matriz{
	friend ostream&operator<<(ostream&,const simetrica&);
	private:
	
	public:
		simetrica(int);
	virtual simetrica*suma(const matriz&)const;
	virtual void f1(matriz&B){
		cout<<"ESTAMOS EN LA CLASE SIMETRICA\n";
	}
};

int main(int argc, char** argv) {
	matriz A(3,3),B(3,3);
	//cout<<"A=\n"<<A;
	//cout<<"B=\n"<<B;
	//cout<<"A+B=\n"<<*(A+B);
	//cout<<"A-B=\n"<<A-B;
	simetrica s(5),r(5);
	//cout<<"A.n="<<A.n;
	//cout<<"s=\n"<<s;
	//cout<<"r=\n"<<r;
	//matriz &refs=s;
	//matriz &refr=r;
	//cout<<"s+r=\n"<<s+r;
	//cout<<"s.n="<<s.n;
	//cout<<"s-r=\n"<<s-r;
	
	matriz**Matrices=new matriz*[2];
	Matrices[0]=&A;
	Matrices[1]=&r;
	Matrices[0]->f1(B);
	(*Matrices[1]).f1(r);
	
	//Matrices[0]=(A+B);
	matriz*ptrr=&r;
	matriz*ptrs=&s;
	Matrices[1]=ptrr->suma(*ptrs);//(r+s)
	/*cout<<"*Matrices[0]=\n";
	cout<<*Matrices[0];
	cout<<"*Matrices[1]=\n";
	cout<<*Matrices[1];*/
	
	
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
	escribir<<"Clase Matriz\n";
	escribir<<"********************************************\n";
	for(int i=0;i<A.n;i++)
		{for(int j=0;j<A.m;j++)
			escribir<<setw(4)<<A.elementos[i][j];
		escribir<<endl;
		}
return escribir;
}

matriz*matriz::suma(const matriz&B)const{

cout<<"ESTAMOS EN LA SUMA DE LA CLASE MATRIZ\n\n;";
if(n==B.n&&m==B.m){
	matriz*c=new matriz(n,m);//matriz c(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			c->elementos[i][j]=elementos[i][j]+B.elementos[i][j];
	
return c;
}

else{
	matriz *c=new matriz();
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
	escribir<<"Clase simetrica\n";
	escribir<<"********************************************\n";
	for(int i=0;i<A.n;i++)
		{for(int j=0;j<A.m;j++)
			escribir<<setw(4)<<A.elementos[i][j];
		escribir<<endl;
		}
return escribir;
}

simetrica *simetrica::suma(const matriz&B)const{
cout<<"ESTAMOS EN LA SUMA DE LA CLASE SIMETRICA\n\n;";

if(n==B.n&&m==B.m){
	simetrica*c=new simetrica(n);//matriz c(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			c->
			
			elementos[i][j]=elementos[i][j]+B.elementos[i][j];
	
return c;
}

else{
	simetrica*c=new simetrica(n);
	
	return c;
}	
}

