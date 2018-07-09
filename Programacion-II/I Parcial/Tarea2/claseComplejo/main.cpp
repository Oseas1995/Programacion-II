#include <iostream>
#include <cmath>

using namespace std;

class complejo{
	friend complejo operator -(const complejo&, const complejo&);
	friend complejo operator *(int, const complejo&);
	friend ostream& operator <<(ostream&, const complejo&);

	private:
		float real;
		float imaginario;
	public:
		complejo();
		complejo(float, float);
		complejo* operator +(const complejo&) const;
		double modulo();
		complejo conjugado();

};


int main(int argc, char** argv) {
	//complejo z;
	//cout<<"z: "<<z<<endl;
	complejo z1(2,3);
	complejo w(3,-2);
	cout<<"z1: "<<z1<<endl;
	cout<<"W: "<<w<<endl;
	cout<<"**************"<<endl;
	cout<<"Multiplicacion de w por un escalar 3"<<endl;
	complejo w1=3*w;
	cout<<w1<<endl;
	complejo *z3=w+z1;
	cout<<"La suma de ("<<w<<") + ("<<z1<<") es: "<<*z3<<endl;
	complejo z4=w-z1;
	cout<<"La resta de ("<<w<<") - ("<<z1<<") es: "<<z4<<endl;

	cout<<"Modulo de W: "<<w.modulo()<<endl;

	cout<<"conjugado de w: ";
	w.conjugado();


	return 0;
}

//constructor por defecto
complejo::complejo(){

}

//constructor alternativo
complejo::complejo(float a, float b){
	real=a;
	imaginario=b;
}

//sobrecarga de suma (+)
complejo* complejo::operator +(const complejo& w) const{
	complejo *s = new complejo();
	s->real=real+w.real;
	s->imaginario=imaginario+w.imaginario;

	return s;
}

//Sobrecarga de cout (<<)
ostream& operator <<(ostream& escribir, const complejo& z){
	if(z.imaginario>=0){
		escribir<<z.real<<"+"<<z.imaginario<<"i";
	}
	else{
		escribir<<z.real<<z.imaginario<<"i";
	}
	return escribir;
}

//Sobrecarga de resta (-)
complejo operator-(const complejo&z, const complejo&w){
	complejo r;
	r.real=z.real-w.real;
	r.imaginario=z.imaginario-w.imaginario;

	return r;
}

//Sobrecarga de multiplicacion por escalar (*)
complejo operator*(int x,const complejo&z){
	complejo w;
	w.real=x*z.real;
	w.imaginario=x*z.imaginario;

	return w;
}

//Funcion modulo
double complejo::modulo(){
	double mod;
	mod=sqrt(pow(real,2)+pow(imaginario,2));
	return mod;
}

//funcion conjugado
complejo complejo::conjugado(){
	if(imaginario>=0){
		cout<<real<<"-"<<imaginario<<"i";
	}else{
		cout<<real<<"+"<<(-1)*imaginario<<"i";
	}
	return *this;
}




