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

class tridiagonal:public matriz{
	friend tridiagonal* operator*(float, const tridiagonal&);
	private:
		float* diagprin;
		float* diaginf;
		float* diagsup;
	public:
		tridiagonal();
		tridiagonal(int);
		~tridiagonal();
		virtual void imprimir()const;
		tridiagonal* operator+(const tridiagonal&)const;
		tridiagonal* operator-(const tridiagonal&)const;
		tridiagonal* operator*(const tridiagonal&)const;
		virtual float traza()const;
		tridiagonal* transpuesta()const;

};

int main(int argc, char** argv) {
	srand(time(0));

	tridiagonal t1(3), t2(3);
	matriz& reft1 = t1;
	matriz& reft2 = t2;

	matriz* s= reft1 + reft2;

	t1.imprimir();
	t2.imprimir();
	s->imprimir();

	delete s;
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

//##############################Inicio de funciones de la clase Tridiagonal.##############################
tridiagonal::tridiagonal(){
	n=3;
	m=3;
	diagprin = new float[n];
	diaginf = new float[n-1];
	diagsup = new float[n-1];
	for(int i=0;i<n-1;i++){
		diagprin[i]=1;
		diaginf[i]=1;
		diagsup[i]=1;
	}

	diagprin[n-1]=1;

}

tridiagonal::tridiagonal(int orden){
	n=orden;
	m=orden;
	diagprin = new float[n];
	diaginf = new float [n-1];
	diagsup = new float [n-1];
	for(int i=0;i<n-1;i++){
		diagprin[i] = rand()%10;
		diaginf[i] = rand()%10;
		diagsup[i] = rand()%10;
	}
	diagprin[n-1] = rand()%10;
}

tridiagonal::~tridiagonal(){
	delete[] diagprin;
	delete[] diaginf;
	delete[] diagsup;
}

void tridiagonal::imprimir() const{
	cout<<"********************************************\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i-j==0)
				cout<<setw(5)<<diagprin[i];
			else
				if(i-j==1)
					cout<<setw(5)<<diaginf[j];
			else
				if(i-j==-1)
					cout<<setw(5)<<diagsup[i];
				else
					cout<<setw(5)<<0;
		}
		cout<<endl;
	}

}

tridiagonal* tridiagonal::operator+(const tridiagonal& t)const{
	tridiagonal* s = new tridiagonal(n);
	for(int i=0;i<n-1;i++){
		s->diagprin[i] = diagprin[i] + t.diagprin[i];
		s->diaginf[i] = diaginf[i] + t.diaginf[i];
		s->diagsup[i] = diagsup[i] + t.diagsup[i];
	}
	s->diagprin[n-1]=diagprin[n-1] + t.diagprin[n-1];
	return s;
}

tridiagonal* tridiagonal::operator-(const tridiagonal& t)const{
	tridiagonal* r = new tridiagonal(n);
	for(int i=0;i<n-1;i++){
		r->diagprin[i] = diagprin[i] - t.diagprin[i];
		r->diaginf[i] = diaginf[i] - t.diaginf[i];
		r->diagsup[i] = diagsup[i] - t.diagsup[i];
	}
	r->diagprin[n-1]=diagprin[n-1] - t.diagprin[n-1];
	return r;
}

tridiagonal* operator*(float k, const tridiagonal& t){
	tridiagonal *m = new tridiagonal(t.n);
	for(int i=0;i<t.n-1;i++){
		m->diagprin[i] = k*t.diagprin[i];
		m->diaginf[i] = k*t.diaginf[i];
		m->diagsup[i] = k*t.diagsup[i];
	}
	m->diagprin[t.n-1]=k*t.diagprin[t.n-1];
	return m;
}

tridiagonal* tridiagonal::transpuesta()const{
	tridiagonal *t = new tridiagonal(n);
	for(int i=0;i<n-1;i++){
		t->diagprin[i]=diagprin[i];
		t->diaginf[i]=diagsup[i];
		t->diagsup[i]=diaginf[i];
	}
	t->diagprin[n-1]=diagprin[n-1];
	return t;
}

float tridiagonal::traza()const{
	float t=0;
	for(int i=0;i<n;i++){
		t+=diagprin[i];
	}
	return t;
}

//##############################Fins de funciones de la clase Tridiagonal.##############################



