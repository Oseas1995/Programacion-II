#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class polinomio{
	friend ostream& operator <<(ostream&,const polinomio&);
	private:
		float *coef;
		int grado;
	public:
		polinomio();
		polinomio(int);
		~polinomio();
		polinomio operator +(const polinomio&)const;
		polinomio operator *(const polinomio&)const;
		polinomio operator -(const polinomio&)const;
		float valor_numerico(float);
		polinomio derivada();
		polinomio antiderivada();
		float integral_definida(float,float);
};

int main(){
	polinomio p;
	cout<<"p(x)="<<p;
	polinomio a(5);
	cout<<"\na(x)="<<a;
	polinomio b(2);
	cout<<"\nb(x)="<<b;
	cout<<"\n(a-p)(x)"<<a-p;
	cout<<"\n(p+a)(x)="<<p+a;
	cout<<"\n(a*b)(x)"<<a*b;
	cout<<"\np(5)="<<p.valor_numerico(5);
	cout<<"\na(2)="<<a.valor_numerico(2);
	cout<<"\np'(x)="<<p.derivada();
	cout<<"\na'(x)="<<a.derivada();
	cout<<"\nP(X)="<<p.antiderivada();
	cout<<"\nA(X)="<<a.antiderivada();
	cout<<"\nP(X)[1,2]="<<p.integral_definida(1,2);
	
	
	
	
	return 0;
}

polinomio:: polinomio(){
	grado=2;
	coef=new float[grado+1];
	for(int i=0;i<grado+1;i++){
		coef[i]=1;
	}
	
}

polinomio::polinomio(int n){
	grado=n;
	coef=new float[grado+1];
	coef[grado]=1+rand()% 10;
	for(int i=0;i<grado;i++){
		coef[i]=rand()% 10;
	}
}
polinomio::~polinomio(){
	delete[]coef;
}

polinomio polinomio::operator +(const polinomio&p)const{

if(grado>=p.grado){
	polinomio c(grado);
	for(int i=0;i<p.grado+1;i++){
		c.coef[i]=coef[i]+p.coef[i];
	}
	for(int i=p.grado+1;i<grado+1;i++){
		c.coef[i]=coef[i];
	}
	return c;
	
}
else{
	polinomio c(p.grado);
	for(int i=0;i<grado+1;i++){
		c.coef[i]=coef[i]+p.coef[i];
	}
	for(int i=grado+1;i<p.grado+1;i++){
		c.coef[i]=p.coef[i];
	}
	return c;
	
}
}

polinomio polinomio::operator -(const polinomio&p)const{

if(grado>=p.grado){
	polinomio c(grado);
	for(int i=0;i<p.grado+1;i++){
		c.coef[i]=coef[i]-p.coef[i];
	}
	for(int i=p.grado+1;i<grado+1;i++){
		c.coef[i]=coef[i];
	}
	return c;
	
}
else{
	polinomio c(p.grado);
	for(int i=0;i<grado+1;i++){
		c.coef[i]=coef[i]-p.coef[i];
	}
	for(int i=grado+1;i<p.grado+1;i++){
		c.coef[i]=p.coef[i];
	}
	return c;
	
}
}

polinomio polinomio::operator *(const polinomio&p)const{
polinomio c(grado+p.grado);
for(int i=0;i<grado+p.grado+1;i++){
	c.coef[i]=0;
}
for(int i=0;i<grado+1;i++){
	for(int j=0;j<p.grado+1;j++){
		c.coef[i+j]+=coef[i]*p.coef[j];
	}
} 
return c;
}

float polinomio::valor_numerico(float n){
	float t=0;
	for(int i=0;i<grado+1;i++){
		t+=coef[i]*pow(n,i);
	}
	return t;
	
}

polinomio polinomio::derivada(){
	polinomio c(grado-1);
	for(int i=0;i<grado;i++){
		c.coef[i]=(i+1)*coef[i+1];
	}
	return c;
}

polinomio polinomio::antiderivada(){
	polinomio c(grado+1);
	c.coef[0]=0;
	for(int i=1;i<grado+2;i++){
		c.coef[i]=(coef[i-1]/i);
	}
	return c;
}

float polinomio::integral_definida(float a,float b){
	polinomio c=this->antiderivada();
	float t=0,s=0,m=0;
	t=c.valor_numerico(a);
	s=c.valor_numerico(b);
	m=t-s;
	return m;
}

ostream& operator <<(ostream&cout,const polinomio&p){
	cout<<p.coef[p.grado]<<"x^"<<p.grado;
	for(int i=p.grado-1;i>0;i--){
		if(p.coef[i]>=0){
			cout<<"+"<<p.coef[i]<<"x^"<<i;
		}
		else{
			cout<<p.coef[i]<<"x^"<<i;
		}
	}
	if(p.coef[0]>=0){
		cout<<"+"<<p.coef[0];
	}
	else{
		cout<<p.coef;
	}
}


