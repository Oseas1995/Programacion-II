#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<class T>
class polinomio{
	friend ostream&operator<<( ostream&escribe,polinomio<T>&p){
		escribe<<"Hola mundo\n";
return escribe;
	}
	private:
		int grado;
		T*coe;
	public:
		polinomio();
		polinomio(int);
		~polinomio();
		void imprimir();
		polinomio<T> operator+(const polinomio<T>&)const;
		T valor_numerico(T)const;
	    polinomio<T> derivada()const;
};
int main(int argc, char** argv) {
	
	return 0;
}

template<class T>
polinomio<T>::polinomio(){
	grado=2;
	coe=new T[grado+1];
	coe[0]=1;
	coe[1]=1;
	coe[2]=1;
}

template<class T>
polinomio<T>::polinomio(int n){
	grado=n;
	coe=new T[grado+1];
	for(int i=0;i<grado;i++)
		coe[i]=rand()%10;
	coe[grado]=1+rand()%9;
}

template<class T>
polinomio<T>::~polinomio(){
	delete[]coe;
}

template<class T>
polinomio<T> polinomio<T>::operator+(const polinomio<T>&q)const{
	int mayor,menor;
	if(grado>q.grado)
		{mayor=grado;
		menor=q.grado;
		}
	else{
		mayor=q.grado;
		menor=grado;
	}
	
	polinomio<T> s(mayor);
	for(int i=0;i<=menor;i++)
		s.coe[i]=coe[i]+q.coe[i];

if(grado==mayor)
	for(int i=menor+1;i<=mayor;i++)
		s.coe[i]=coe[i];
else		
	for(int i=menor+1;i<=mayor;i++)
		s.coe[i]=q.coe[i];

for(int k=mayor;s.coe[k]==0;k--){
s.grado=k;
}





return s;
}

template<class T>
T polinomio<T>:: valor_numerico(T x)const{
	T s=0;
	
	for(int i=0;i<=grado;i++)
		s+=coe[i]*pow(x,i);
		
return s;
}

template<class T>
polinomio<T> polinomio<T>::derivada()const{
polinomio<T> d(grado-1);
for(int i=grado;i>=1;i--)
	d.coe[i-1]=coe[i]*i;

return d;
}

