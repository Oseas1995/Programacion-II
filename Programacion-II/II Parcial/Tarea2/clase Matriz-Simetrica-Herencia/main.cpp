#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class matriz{
	friend matriz* operator-(const matriz&,const matriz&);
	friend matriz* operator*(float, const matriz&);
	private:

	protected:
		int n, m;
		float **elementos;
	public:
		matriz();
		matriz(int, int);
		~matriz();
		virtual void imprimir() const;
		matriz* operator+(const matriz&)const;
		matriz* operator*(const matriz&)const;
		bool esSimetrica();
		virtual float traza() const;
		matriz* transpuesta();


};

class simetrica:public matriz{
	friend simetrica* operator-(const simetrica&,const simetrica&);
	friend simetrica* operator*(float, const simetrica&);
	private:

	public:
		simetrica();
		simetrica(int);
		//~simetrica();
		virtual void imprimir()const;
		simetrica* operator+(const simetrica&)const;
		simetrica* operator*(const simetrica&)const;
		virtual float traza()const;
		simetrica* transpuesta()const;


};

int main(int argc, char** argv) {
	srand(time(0));

	simetrica s1(3), s2(3);
	matriz &refs1 = s1;
    matriz &refs2 = s2;

 	cout<<"Taza s1: "<<refs1.traza()<<endl;
 	matriz *m3 = refs1+refs2;


 	refs1.imprimir();
    refs2.imprimir();
	return 0;
}

//##############################Inicio de funciones de la clase Matriz.##############################
matriz::matriz(){
	n=3;
	m=3;
	elementos = new float*[n];
	for(int i=0;i<n;i++)
		elementos[i] = new float[m];

	elementos[0][0] = 1;
	elementos[0][1] = 0;
	elementos[0][2] = 0;
	elementos[1][0] = 0;
	elementos[1][1] = 1;
	elementos[1][2] = 0;
	elementos[2][0] = 0;
	elementos[2][1] = 0;
	elementos[2][2] = 1;
}

matriz::matriz(int nF, int nC){
	n=nF;
	m=nC;
	elementos = new float*[n];
	for(int i=0;i<n;i++)
		elementos[i] = new float[m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			elementos[i][j]=rand()%100;
	}

}

matriz::~matriz(){
	for(int i=0;i<n;i++)
		delete[] elementos[i];

	delete[] elementos;
}

void matriz::imprimir() const{
	cout<<"********************************************\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<setw(5)<<elementos[i][j];
		cout<<endl;
	}

}

matriz* matriz::operator+(const matriz& b)const{
	cout<<"ESTAMOS EN LA SUMA DE LA CLASE MATRIZ\n\n";
	if(n==b.n && m==b.m){
		matriz* c = new matriz(n, m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				c->elementos[i][j]=elementos[i][j] + b.elementos[i][j];
		}
		return c;
	}else{
		matriz* c = new matriz();
		return c;
	}
}


 matriz* operator-(const matriz& a,const matriz& b){
 	cout<<"ESTAMOS EN LA RESTA DE LA CLASE MATRIZ\n\n";
	if(a.n==b.n && a.m==b.m){
		matriz* c = new matriz(a.n, a.m);
		for(int i=0;i<a.n;i++){
			for(int j=0;j<a.m;j++)
				c->elementos[i][j]=a.elementos[i][j] - b.elementos[i][j];
		}
		return c;
	}else{
		matriz* c = new matriz();
		return c;
	}
 }


 matriz* operator*(float k, const matriz& b){
 	cout<<"ESTAMOS EN LA MULTIPLICACION DE MATRIZ\n\n";
 	matriz *mul = new matriz(b.n, b.m);
	for(int i=0;i<b.n;i++)
		for(int j=0;j<b.m;j++)
			mul->elementos[i][j]=k*b.elementos[i][j];
	return mul;
 }


 matriz* matriz::operator*(const matriz& b)const{
	if(m==b.n){
		matriz *mul = new matriz(n, b.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<b.m;j++)
				mul->elementos[i][j]=0;

		for(int i=0;i<n;i++)
			for(int j=0;j<b.m;j++)
				for(int k=0;k<b.m;k++)
					mul->elementos[i][j]+=elementos[i][k]*b.elementos[k][j];


		return mul;
	}else{
		matriz *mul = new matriz();
		return mul;
	}
}


bool matriz::esSimetrica(){
	bool resp = false;
	matriz* a= this->transpuesta();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(elementos[i][j]==(a->elementos[i][j])){
				resp=true;
			}else{
				resp=false;
				break;
			}
		}
	}

	return resp;
}

float matriz::traza() const{
	float s=0;
	for(int i=0;i<n;i++)
		s+=elementos[i][i];

	return s;
}


matriz* matriz::transpuesta(){
	matriz *t = new matriz(n,m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		    t->elementos[i][j]=elementos[j][i];

	}
	return t;
}

//##############################Fin de funciones de la clase Matriz.##############################


//##############################Inicio de funciones de la clase Simetrica.##############################

simetrica::simetrica(){
	n=3;
	elementos = new float*[n];
	for(int i=0;i<n;i++)
		elementos[i] = new float[n];

	elementos[0][0] = 1;
	elementos[0][1] = 0;
	elementos[0][2] = 0;
	elementos[1][0] = 0;
	elementos[1][1] = 1;
	elementos[1][2] = 0;
	elementos[2][0] = 0;
	elementos[2][1] = 0;
	elementos[2][2] = 1;
}

simetrica::simetrica(int dim){
	n=dim;
	elementos = new float*[n];
	for(int i=0;i<n;i++){
		elementos[i]=new float[i+1];
		for(int j=0;j<i+1;j++)
			elementos[i][j]	= rand()%10;

	}
}

void simetrica::imprimir() const{
	cout<<"********************************************\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++)
			cout<<setw(5)<<elementos[i][j];

		for(int k=i+1;k<n;k++)
			cout<<setw(5)<<elementos[k][i];

		cout<<endl;
	}
	cout<<endl;
}

simetrica* simetrica::operator+(const simetrica& s)const{
	if(n==s.n && m==s.m){
		simetrica* c = new simetrica(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<i+1;j++)
				c->elementos[i][j]=elementos[i][j] + s.elementos[i][j];
		}
		return c;
	}else{
		simetrica* c = new simetrica();
		return c;
	}
}

simetrica* operator-(const simetrica&s1,const simetrica&s2){

	if(s1.n==s2.n && s1.m==s2.m){
		simetrica* c = new simetrica(s1.n);
		for(int i=0;i<s1.n;i++){
			for(int j=0;j<i+1;j++)
				c->elementos[i][j]=s1.elementos[i][j] - s2.elementos[i][j];
		}
		return c;
	}else{
		simetrica* c = new simetrica();
		return c;
	}
}

simetrica* operator*(float k, const simetrica& s){
	simetrica *mul = new simetrica(s.n);
	for(int i=0;i<s.n;i++)
		for(int j=0;j<i+1;j++)
			mul->elementos[i][j]=k*s.elementos[i][j];
	return mul;
}

simetrica* simetrica::operator*(const simetrica& s)const{

	if(m==s.n){
		simetrica *mul = new simetrica(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<s.n;j++)
				mul->elementos[i][j]=0;

		for(int i=0;i<n;i++)
			for(int j=0;j<s.n;j++)
				for(int k=0;k<s.n;k++)
					mul->elementos[i][j]+=elementos[i][k]*s.elementos[k][j];


		return mul;
	}else{
		simetrica *mul = new simetrica();
		return mul;
	}
}

float simetrica::traza()const{
	float s=0;
	for(int i=0;i<n;i++)
		s+=elementos[i][i];

	return s;
}

simetrica* simetrica::transpuesta()const{
	simetrica *t = new simetrica(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++)
		    t->elementos[i][j]=elementos[i][j];

	}
	return t;
}

//##############################Fin de funciones de la clase Simetrica.##############################


