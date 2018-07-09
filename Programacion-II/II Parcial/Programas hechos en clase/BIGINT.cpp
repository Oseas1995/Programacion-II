#include <iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class bigint{
	friend ostream&operator<<(ostream &escribir,const bigint&x){
	if(x.signo<0)
		escribir<<"-";	
	for(int i=x.n-1;i>=0;i--)
		cout<<x.digitos[i];
	
	return escribir;	
	
	}
	private:
		int n;//n:Número de digitos que tiene el entero grande
		int*digitos;
		int signo;
	public:
		bigint();
		bigint(int,int);//(n,signo)
		~bigint();
		bigint operator+(const bigint&)const;
};

int main(int argc, char** argv) {
	srand(time(0));
	bigint x(30,1),y(20,1);
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	cout<<"x+y="<<x+y<<endl;
	return 0;
}

bigint::bigint(){
	n=3;
	signo=1;
	digitos=new int[n];
	digitos[0]=1;
	digitos[1]=2;
	digitos[2]=3;
}

bigint::bigint(int longitud,int sig){
	n=longitud;
	signo=sig;
	digitos=new int[n];
	for(int i=0;i<n-1;i++)
		digitos[i]=rand()%10;
		
	digitos[n-1]=1+rand()%9;
}

bigint::~bigint(){
	delete[]digitos;
}


bigint bigint::operator+(const bigint&y)const{
if(signo==y.signo){
	
	int mayor, menor;
	if(n>y.n){
		mayor=n,
		menor=y.n;
	}
	else{
		mayor=y.n,
		menor=n;
	}
		
	bigint *s=new bigint(mayor+1,signo);
	int k=0,t;
	for(int i=0;i<mayor;i++){
		if(i<menor){
			t=digitos[i]+y.digitos[i]+k;
			s->digitos[i]=t%10;
			k=(t-t%10)/10;
		}
		else{
			if(n==mayor){
				t=digitos[i]+k;
			s->digitos[i]=t%10;
			k=(t-t%10)/10;	
			}
			else{
				t=y.digitos[i]+k;
			s->digitos[i]=t%10;
			k=(t-t%10)/10;
			}
		}
		
	}
	
	if(k==1){
		s->digitos[mayor-1]=1;
	}
	else{
		
		s->n=mayor;
	}
	
	return *s;
}

}
