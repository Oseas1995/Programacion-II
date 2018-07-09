#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

class matriz{
	friend matriz operator -(const matriz&,const matriz&);
	friend ostream& operator <<(ostream&,const matriz&);
	protected:
		int dim,dim1;
		float**elementos;
	public:
		matriz();
		matriz(int,int);
		~matriz();
		matriz operator +(const matriz&)const;
		matriz transpuesta();
		matriz operator *(const matriz&)const;
		bool simetrica();
		int traza();
		
};

class simetrica:public matriz{
	friend simetrica operator *(int,const simetrica&);
	friend ostream& operator <<(ostream&,const simetrica&);
	private:
		
		
	public:
		simetrica();
		simetrica(int);
		~simetrica();
		simetrica operator +(const simetrica&)const;
		simetrica operator -(const simetrica&)const;
		simetrica operator *(const simetrica&)const;
		int traza();
		
		
		
	
};

int main(){
	matriz A;
	cout<<A;
	matriz B(5,5);
	cout<<"\n"<<B;
	matriz D(5,5);
	cout<<"\n"<<D;
	matriz C=B+D;
	cout<<"\n"<<C;
	matriz E=B-D;
	cout<<"\n"<<E;
	matriz F=B*D;
	cout<<"\n"<<F;
//	matriz T=B.transpuesta();
//	cout<<"\n"<<T;
	simetrica S;
	cout<<"\n"<<S;
	simetrica L(4);
	cout<<"\n"<<L;
	simetrica M(4);
	cout<<"\n"<<M;
	cout<<"\n"<<L+M;
	cout<<"\n"<<L-M;
	cout<<"\n"<<L*M;
	cout<<"\n"<<2*L;
	cout<<"\n"<<D.traza();
	cout<<"\nS="<<S.traza();
	
	
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
	
	matriz matriz::operator *(const matriz&A)const{
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

ostream& operator <<(ostream& cout,const matriz&A){
	cout<<"**************************************"<<endl;
	cout<<"CLASE MATRIZ"<<endl;
	for (int i=0;i<A.dim;i++){
		for (int j=0;j<A.dim1;j++){
			cout<<A.elementos[i][j]<<setw(4);
		}
		cout<<"\n"<<setw(2);
	}
}

simetrica::simetrica(){
	dim=3;
	elementos=new float*[dim];
	for(int i=0;i<dim;i++){
		elementos[i]=new float[i+1];
	}
	elementos[0][0]=1;
	elementos[0][1]=0;
	elementos[0][2]=0;
	elementos[1][0]=0;
	elementos[1][1]=1;
	elementos[1][2]=0;
	elementos[2][0]=0;
	elementos[2][1]=0;
	elementos[2][2]=1;
}

simetrica::simetrica(int n){
	dim=n;
	int temp;
	elementos=new float*[dim];
	for(int i=0;i<dim;i++){
		elementos[i]=new float[i+1];
	}
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
		
		temp=10+rand()% 50;
		elementos[i][j]=temp;
		elementos[j][i]=temp;
	}
	}
}

simetrica::~simetrica(){
	for(int i=0;i<dim;i++){
		delete[]elementos[i];
	}
	delete[]elementos;
}

simetrica simetrica::operator +(const simetrica&P)const{
	simetrica C(dim);
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				C.elementos[i][j]=elementos[i][j]+P.elementos[i][j];
			}
		}
		return C;
	}


simetrica simetrica::operator -(const simetrica&B)const{
		simetrica C(dim);
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				C.elementos[i][j]=elementos[i][j]-B.elementos[i][j];
			}
		}
		return C;

}

simetrica operator *(int n,const simetrica&B){
	simetrica C(B.dim);
	for(int i=0;i<B.dim;i++){
		for(int j=0;j<B.dim;j++){
			C.elementos[i][j]=n*B.elementos[i][j];
		}
	}
	return C;
}

	simetrica simetrica::operator *(const simetrica&A)const{
	simetrica D(dim);

	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			for(int k=0;k<dim;k++){
				D.elementos[i][j]+=elementos[i][k]*A.elementos[k][j];
			}
		}
	}
	return D;
	}
	
	int simetrica::traza(){
	int t=0;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(i==j){
				t+=elementos[i][j];
			}
		}
	}
	return t;
}
ostream& operator <<(ostream& cout,const simetrica&A){
	cout<<"**************************************"<<endl;
	cout<<"CLASE SIMETRICA"<<endl;
	for (int i=0;i<A.dim;i++){
		for (int j=0;j<A.dim;j++){
			cout<<A.elementos[i][j]<<setw(4);
		}
		cout<<"\n";
	}
}
