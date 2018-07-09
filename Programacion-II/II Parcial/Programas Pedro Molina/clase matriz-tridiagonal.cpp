#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

class matriz{
	friend matriz operator -(const matriz&,const matriz&);

	protected:
		int dim,dim1;
		float**elementos;
	public:
		matriz();
		matriz(int,int);
		~matriz();
	virtual	void imprimir();
		matriz operator +(const matriz&)const;
		matriz transpuesta();
		matriz operator *(const matriz&)const;
		bool simetrica();
	virtual	int traza();
		
};

class tridiagonal:public matriz{
	friend tridiagonal operator *(float,const tridiagonal&);
	private:
		float*diag;
		float*diagsup;
		float*diaginf;
	public:
		tridiagonal();
		tridiagonal(int);
		~tridiagonal();
	virtual	void imprimir();
		tridiagonal operator +(const tridiagonal&)const;
		tridiagonal operator -(const tridiagonal&)const;
		tridiagonal transpuesta();
	virtual	int traza();
				
};


int main(){
	matriz A;
	cout<<"A="<<endl;
	A.imprimir();
	matriz B(5,5);
	cout<<"B="<<endl;
	B.imprimir();
	matriz D(5,5);
	cout<<"D="<<endl;
	D.imprimir();
	matriz C=B+D;
	cout<<"C="<<endl;
	C.imprimir();
	matriz E=B-D;
	cout<<"E="<<endl;
	E.imprimir();
//	matriz F=B*D;
//	cout<<"\n"<<F;
//	matriz T=B.transpuesta();
//	cout<<"\n"<<T;
cout<<"********************************************Matriz Tridiagonal***********************************"<<endl;

tridiagonal T;
T.imprimir();
tridiagonal M(5);
cout<<"M="<<endl;
M.imprimir();
	
tridiagonal S(5);
/*matriz*q=&S;
cout<<"S="<<endl;
q->imprimir();
tridiagonal P=M+S;
cout<<"P="<<endl;
P.imprimir();
int p=q->traza();
cout<<"trS="<<p<<endl;
*/


	return 0;
}

matriz::matriz(){
	dim=2;
	dim1=2;
	elementos=new float*[dim];
	for(int i=0;i<dim;i++){
		elementos[i]=new float[dim1];
	}
    elementos[0][0]=1;
    elementos[0][1]=0;
    elementos[1][0]=0;
    elementos[1][1]=1;
}

matriz::~matriz(){
	for(int i=0;i<dim;i++){
		delete[]elementos[i];
	}
	delete[]elementos;
}

matriz::matriz(int n,int m){
	dim=n;
	dim1=m;
	elementos=new float*[n];
	for (int i=0;i<n;i++){
		elementos[i]=new float[m];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			elementos[i][j]=rand()% 50;
		}
	}
	
	
}


matriz matriz::operator +(const matriz&P)const{
	matriz C(dim,dim1);
	if(dim==P.dim && dim1==P.dim1){
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim1;j++){
				C.elementos[i][j]=elementos[i][j]+P.elementos[i][j];
			}
		}
		return C;
	}
}

matriz operator -(const matriz&A,const matriz&B){
		matriz C(A.dim,A.dim1);
	if(A.dim==B.dim && A.dim1==B.dim1){
		for(int i=0;i<A.dim;i++){
			for(int j=0;j<A.dim1;j++){
				C.elementos[i][j]=A.elementos[i][j]-B.elementos[i][j];
			}
		}
		return C;
	}
}

/*matriz matriz:: transpuesta(){
	matriz T(dim1,dim);
	for(int i=0;i<dim1;i++){
		for(int j=0;i<dim;j++)
		if(i<j){
		T.elementos[i][j]=elementos[j][i];
	}
	}
	return T;
}

/*bool matriz::simetrica(){
	int t=0;
	matriz D=this->transpuesta();
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim1;j++){
			if(D.elementos[i][j]==elementos[i][j]){
				t=t+1;
			}
		
		}
	}
	return t==dim+dim1;
}
*/
	
/*	matriz matriz::operator *(const matriz&A)const{
	matriz D(dim,A.dim1);
	for (int i=0;i<dim;i++){
		for (int j=0;j<A.dim;j++){
			for(int k=0;k<dim1;k++){
				D.elementos[i][j]+=elementos[i][k]*A.elementos[k][j];
			}
		}
	}
	return D;
	}
*/	
int matriz::traza(){
	int t=0;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim1;j++){
			if(i==j){
				t+=elementos[i][j];
			}
		}
	}
	return t;
}

void matriz::imprimir(){

	cout<<"**************************************"<<endl;
	cout<<"CLASE MATRIZ"<<endl;
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim1;j++){
			cout<<elementos[i][j]<<setw(4);
		}
		cout<<"\n"<<setw(2);
	}
}

tridiagonal::tridiagonal(){
	dim=3;
diag=new float[dim];
diagsup=new float[dim-1];
diaginf=new float[dim-1];
diag[0]=1;
diag[1]=1;
diag[2]=1;
diagsup[0]=1;
diagsup[1]=1;
diaginf[0]=1;
diaginf[1]=1;

}

tridiagonal::tridiagonal(int n){
	dim=n;
	dim1=n;
diag=new float[dim];
diagsup=new float[dim-1];
diaginf=new float[dim-1];
for(int i=0;i<dim-1;i++){
	diag[i]=1+rand()% 10;
	diagsup[i]=1+rand()% 10;
	diaginf[i]=1+rand()% 10;
	
}
diag[dim-1]=1+rand()% 9;
	
}

tridiagonal::~tridiagonal(){
	delete[]diag;
	delete[]diagsup;
	delete[]diaginf;
}

void tridiagonal::imprimir(){
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(i-j==0){
				cout<<setw(4)<<diag[i];
			}
			else{
			
			    if(j-i==1){
			    	cout<<setw(4)<<diagsup[i];
				}
				else {
				
				    if(i-j==1){
				    	cout<<setw(4)<<diaginf[j];
					}
					else{
					
					    cout<<setw(4)<<0;
				}
	      	}
    }
		}
		cout<<endl;
		
	}
	
}

tridiagonal tridiagonal:: operator +(const tridiagonal&T)const{
tridiagonal S(dim);
for(int i=0;i<dim-1;i++){
	S.diag[i]=diag[i]+T.diag[i];
	S.diagsup[i]=diagsup[i]+T.diagsup[i];
	S.diaginf[i]=diaginf[i]+T.diaginf[i];
}
	S.diag[dim-1]=diag[dim-1]+T.diag[dim-1];
return S;
}

tridiagonal tridiagonal:: operator -(const tridiagonal&T)const{
tridiagonal S(dim);
for(int i=0;i<dim-1;i++){
	S.diag[i]=diag[i]-T.diag[i];
	S.diagsup[i]=diagsup[i]-T.diagsup[i];
	S.diaginf[i]=diaginf[i]-T.diaginf[i];
}
	S.diag[dim-1]=diag[dim-1]-T.diag[dim-1];
return S;
}

tridiagonal operator *(float n,const tridiagonal&T){
	tridiagonal s(T.dim);
	for(int i=0;i<T.dim;i++){
	
		s.diag[i]=n*T.diag[i];
		s.diagsup[i]=n*T.diagsup[i];
		s.diaginf[i]=n*T.diaginf[i];
	}
	s.diag[T.dim-1]=n*T.diag[T.dim-1];
	return s;
}

tridiagonal tridiagonal:: transpuesta(){
	tridiagonal s(dim);
	for(int i=0;i<dim-1;i++){
	  s.diagsup[i]=diaginf[i];
	  s.diaginf[i]=diagsup[i];
	}
	return s;
}

int tridiagonal::traza(){
	int s=0;
	for(int i=0;i<dim;i++){
		s+=diag[i];
	}
	return s;
}
