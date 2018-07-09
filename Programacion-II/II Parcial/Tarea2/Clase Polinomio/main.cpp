#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class polinomio{
	friend ostream& operator<<(ostream&, polinomio&);
	private:
		int grado;
		float* coe;
	public:
		polinomio();
		polinomio(int);
		~polinomio();
		polinomio* operator+(const polinomio&)const;
		polinomio* operator-(const polinomio&)const;
		float valor_numerico(float)const;
		polinomio* derivada()const;
		polinomio* antiderivada();
		float integral_definida(float, float);

};

int main(int argc, char** argv) {
	srand(time(0));
	polinomio p1;
	polinomio p2(4);
	polinomio *s = p1 + p2;


	cout<<"p1: "<<p1<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"Suma p1 + p2: "<<*s<<endl;


	delete s;
	return 0;
}

polinomio::polinomio(){
	grado = 2;
	coe = new float[grado+1];
	for(int i=0;i<grado+1;i++){
		coe[i] = 1;
	}
}

polinomio::polinomio(int n){
	grado = n;
	coe = new float[grado+1];
	for(int i=0;i<grado;i++){
		coe[i] = rand()%10;
	}
	coe[grado]=1+rand()%9;
}

polinomio::~polinomio(){
	delete[] coe;
}

ostream& operator<<(ostream& escribir, polinomio& p){
	//escribir<<"*************************************\n\n";
	for(int i=p.grado;i>0;i--){
		if(p.coe[i-1]>=0)
			escribir<<p.coe[i]<<"x^"<<i<<"+";
		else{
			escribir<<p.coe[i]<<"x^"<<i;

		}

	}
	escribir<<p.coe[0]<<endl<<endl;
	return escribir;

}

polinomio* polinomio::operator+(const polinomio& p)const{

	polinomio *s;
	if(grado>p.grado){
		s= new polinomio(grado);
		for(int i=0;i<p.grado+1;i++)
			s->coe[i]=coe[i]+p.coe[i];
		for(int i=p.grado+1;i<grado+1;i++)
			s->coe[i]=coe[i];

	}else{
		s= new polinomio(p.grado);
		for(int i=0;i<grado+1;i++)
			s->coe[i]=coe[i]+p.coe[i];
		for(int i=grado+1;i<p.grado+1;i++)
			s->coe[i]=p.coe[i];
	}

	return s;

}

polinomio* polinomio::operator-(const polinomio& p)const{

	polinomio *r;
	if(grado>p.grado){
		r= new polinomio(grado);
		for(int i=0;i<p.grado+1;i++)
			r->coe[i]=coe[i]-p.coe[i];
		for(int i=p.grado+1;i<grado+1;i++)
			r->coe[i]=coe[i];

	}else{
		r= new polinomio(p.grado);
		for(int i=0;i<grado+1;i++)
			r->coe[i]=coe[i]-p.coe[i];
		for(int i=grado+1;i<p.grado+1;i++)
			r->coe[i]=p.coe[i];
	}

	return r;

}

float polinomio::valor_numerico(float k)const{
	float s=0;
	for(int i=0;i<grado;i++)
		s+=coe[i]*pow(k,i);

	return s;
}

polinomio* polinomio::derivada()const{
	polinomio *der = new polinomio(grado-1);
	for(int i=grado;i>=1;i--){
		der->coe[i-1] = coe[i]*i;
	}
	return der;
}

polinomio* polinomio::antiderivada(){
	polinomio *c = new polinomio(grado+1);
	c->coe[0]=0;
	for(int i=1;i<grado+2;i++){
		c->coe[i]=(coe[i-1]/i);
	}
	return c;
}

float polinomio::integral_definida(float a,float b){
	polinomio *c=this->antiderivada();
	float t=0,s=0,m=0;
	t=c->valor_numerico(a);
	s=c->valor_numerico(b);
	m=t-s;
	return m;
}







