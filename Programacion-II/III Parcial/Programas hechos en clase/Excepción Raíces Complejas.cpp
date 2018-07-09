#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Resuelve la ecuacion: ax^2+bx+c=0
void raices(float a, float b, float c,float &x1,float &x2){
float  discriminante=b*b-4*a*c;
if(discriminante<0)
	throw discriminante;
else
	if(a==0)	
		throw a;
	else{
		x1=(-b+sqrt(discriminante))/2*a;
		x2=(-b-sqrt(discriminante))/2*a;
	}
}

int main(int argc, char** argv) {
	float a,b,c,x1,x2;
	cout<<"a=";cin>>a;
	cout<<"b=";cin>>b;
	cout<<"c=";cin>>c;
	try{
		raices(a,b,c,x1,x2);
		cout<<"las raices son\n x1="<<x1<<"\n x2="<<x2<<endl;
	}
	catch(float error){
		if(error<0)
			cerr<<"La ecuacion "<<a<<" x^2+"<<b<<"x+"<<c<<"=0 no tiene raices reales\n";
		else
			cerr<<"La ecuacion "<<a<<" x^2+"<<b<<"x+"<<c<<"=0 no es un ecuacion cuadratica\n";
	}
	
	system("pause");
	return 0;
}
