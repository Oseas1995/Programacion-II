#include <iostream>

using namespace std;

class complejo{
friend complejo operator-(const complejo&,const complejo&);

private:
   float real, imaginario;
public:
	 
        complejo();
        complejo(float,float);
        void imprimir()const;
        complejo *suma(const complejo &)const;
		complejo operator+(const complejo&)const;
		
		bool operator==(const complejo&)const;
};

int main()
{
    complejo z;
    z.imprimir();
    complejo z1(1,-2);
    z1.imprimir();
    complejo*z3=z.suma(z1); 
    z3->imprimir();
//complejo*z4=z+z1;
//z4->imprimir();
complejo z5=z+z1;

if(z5==z)
cout<<"SOn iguales";
else
cout<<"NO son iguales";
z5.imprimir();

complejo z6=z-z1;
z6.imprimir();
    return 0;
}
complejo::complejo(){
    real=0;
    imaginario=0;
}

complejo::complejo(float a, float b){
    real=a;
    imaginario=b;
}

void complejo::imprimir()const{
    if(imaginario>=0)
        cout << real << "+" << imaginario << "i" << endl << endl;
    else
        cout << real << imaginario << "i" << endl;
}

complejo *complejo::suma(const complejo &z1)const{
    complejo z3;
    z3.real =real + z1.real;
    z3.imaginario =real + z1.imaginario;
    
return &z3;
}

complejo complejo::operator +(const complejo&w)const{
complejo s;
s.real=this->real+w.real;
s.imaginario=imaginario+w.imaginario;



return s;
}


complejo operator-(const complejo&z,const complejo&w){
complejo r;
r.real=z.real-w.real;
r.imaginario=z.imaginario-w.imaginario;

return r;
}


bool complejo::operator==(const complejo&w)const{
return (real==w.real)&&(imaginario==w.imaginario);
}
