#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class bigint{
	friend ostream& operator <<(ostream&,const bigint&);
	private:
		int*digitos;
		int dim;
		int signo;
	public:
		bigint();
		bigint(int);
		~bigint();
		bool operator ==(const bigint&)const;
		bool operator <(const bigint&)const;
		bool operator >(const bigint&)const;
		bigint operator ++(int)const;
		bigint operator --(int)const;
		bigint operator +(const bigint&)const;
};

int main(){
	bigint a;
	bigint b(10);
	bigint c(10);
	
	bigint g(10);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
	cout<<"g="<<g<<endl;
		if (a==a){
		cout<<"a es igual a a"<<endl;
	}
	else{
		cout<<"a no es igual a a"<<endl;
	}
	cout<<"a++="<<a++<<endl;
	cout<<"a--="<<a--<<endl;
	cout<<"a+a="<<a+a<<endl;
	return 0;
}

bigint::bigint(){
	dim=10;
	signo=1;
	digitos=new int[dim];
	digitos[0]=0;
	for(int i=1;i<dim;i++){
		digitos[i]=10-i;
	}
	
}

bigint::bigint(int n){
	dim=n;
	signo=pow(-1,1+rand()% 3);
	digitos=new int[dim];
	digitos[dim-1]=1+rand()% 10;
	for(int i=0;i<dim-1;i++){
		digitos[i]=rand()% 10;
	}
}

bigint::~bigint(){
	delete[]digitos;
}

bool bigint::operator ==(const bigint&c)const{
	int t=0;
if(signo==c.signo){
	if(dim==c.dim){
		for(int i=0;i<dim;i++){
			if(digitos[i]==c.digitos[i]){
				t+=1;
			}
		}
		return t==dim;
	}
	return false;
}
return false;
}
bool bigint::operator <(const bigint&b)const{
if(dim==b.dim){
	if(signo==b.signo){
		for(int i=0;i<dim;i++){
			if(digitos[i]==b.digitos[i]){
				
			}
			else{
				if(digitos[i]<b.digitos[i]){
					return true;
					break;
				}
				else
				return false;
				break;
			}
		}
	}
	else
	if(signo<b.signo){
		return true;
	}
	else{
		return false;
	}
}
}
bool bigint::operator >(const bigint&b)const{
if(dim==b.dim){
	if(signo==b.signo){
		for(int i=0;i<dim;i++){
			if(digitos[i]==b.digitos[i]){
				
			}
			else{
				if(digitos[i]>b.digitos[i]){
					return true;
					break;
				}
				else
				return false;
				break;
			}
		}
	}
	else
	if(signo>b.signo){
		return true;
	}
	else{
		return false;
	}
}
}

bigint bigint::operator ++(int n)const{
	if(signo>0){
	    digitos[0]+=1;
		if(digitos[0]==10){
			digitos[1]+=1;
		}
		return *this;
	}
	
}

bigint bigint::operator --(int n)const{
	if(signo>0){
	    if(digitos[0]==0){
	    	digitos[0]=9;
	    	digitos[1]-=1;
		}
		else{
			digitos[0]-=1;
		}
    return *this;
	    

	
}
}

bigint bigint::operator +(const bigint&b)const{
int mayor,menor,s=0,d=0;
if(dim>b.dim){
	mayor=dim;
	menor=b.dim;
}
else{
	mayor=b.dim;
	menor=dim;
}
bigint c(mayor+1);
for(int i=0;i<mayor;i++){
	if(i<menor){
		s+=digitos[i]+b.digitos[i];
		d=s%10;
		c.digitos[i]=d;
		if(s>d){
			s=1;
		}
		else{
		s=0;	
		}
		}
		else{
			if(mayor==dim){
				if(i==menor){
					c.digitos[i]=s+digitos[i];
				}
				else{
					c.digitos[i]=digitos[i];
				}
			}
			else{
				if(i==menor){
					c.digitos[i]=s+b.digitos[i];
				}
					else{
						c.digitos[i]=b.digitos[i];
					}
				}
			}
	}
		return c;

}





ostream& operator <<(ostream&cout,const bigint&b){
	if(b.signo<0){
		b.digitos[b.dim-1]=-1*b.digitos[b.dim-1];
	}
   for(int i=b.dim-1;i>=0;i--){
   	cout<<b.digitos[i];
   }
}

