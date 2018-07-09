#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class bigint{
	friend bigint operator *(int,const bigint&);
	friend ostream& operator <<(ostream&,const bigint&);
	private:
		int*digitos;
		int dim;
		int signo;
	public:
		bigint();
		bigint(int,int);
		~bigint();
		bool operator ==(const bigint&)const;
		bool operator <(const bigint&)const;
		bool operator >(const bigint&)const;
		bigint operator ++(int)const;
		bigint operator --(int)const;
		bigint operator +(const bigint&)const;
		bigint operator-(const bigint&)const;
		bigint operator%(const bigint&)const;
		bigint operator*(const bigint&)const;
};

int main(){
    bigint a;
	bigint b(10,1);
	bigint c(10,1);
	
	bigint g(10,1);
	bigint f(5,1);
	bigint s(4,1);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
	cout<<"g="<<g<<endl;
	cout<<"f="<<f<<endl;
	cout<<"s="<<s<<endl;
		if (a==a){
		cout<<"a es igual a a"<<endl;
	}
	else{
		cout<<"a no es igual a a"<<endl;
	}
	cout<<"a++="<<a++<<endl;
	cout<<"a--="<<a--<<endl;
	cout<<"b+c="<<b+c<<endl;
	cout<<"c-b="<<c-b<<endl;
	cout<<"c%b="<<c%b<<endl;
//	cout<<"2*a="<<2*a<<endl;
//	cout<<"2*c="<<2*c<<endl;
//	cout<<"5*a="<<5*a<<endl;
	cout<<"f*s="<<s*f<<endl;
	cout<<"a*b="<<a*b<<endl;
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

bigint::bigint(int longitud,int sig){
	dim=longitud;
	signo=sig;
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

bool bigint::operator<(const bigint&n)const{
		if(signo<n.signo)
			return true;
		else
			if(signo>n.signo)
				return false;
			else
				if(signo<0)
					{if(dim<n.dim)
						return true;
					else
						if(dim>n.dim)
							return false;
						else{
							bool resp=true;
							int i=dim-1;
							while(i<=1&&digitos[i]==n.digitos[i])
								{i--;
								}
								
								if(digitos[i]<n.digitos[i])
									resp=true;
								else
									resp=false;
									
							return resp;
						}
					}
				else{
					if(dim>n.dim)
						return true;
					else
						if(dim>n.dim)
							return false;
						else{
							bool resp=true;
							int i=dim-1;
							while(i<=1&&digitos[i]==n.digitos[i])
								{	i--;
								}
								
								if(digitos[i]>n.digitos[i])
									resp=true;
								else
									resp=false;
									
							return resp;
						}
					}	
	}

bool bigint::operator>(const bigint&n)const{
		if(signo>n.signo)
			return true;
		else
			if(signo<n.signo)
				return false;
			else
				if(signo>0)
					{if(dim>n.dim)
						return true;
					else
						if(dim<n.dim)
							return false;
						else{
							bool resp=true;
							int i=dim-1;
							while(i>=1&&digitos[i]==n.digitos[i])
								{i--;
								}
								
								if(digitos[i]>n.digitos[i])
									resp=true;
								else
									resp=false;
									
							return resp;
						}
					}
				else{
					if(dim<n.dim)
						return true;
					else
						if(dim>n.dim)
							return false;
						else{
							bool resp=true;
							int i=dim-1;
							while(i>=1&&digitos[i]==n.digitos[i])
								{	i--;
								}
								
								if(digitos[i]<n.digitos[i])
									resp=true;
								else
									resp=false;
									
							return resp;
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

bigint bigint:: operator+(const bigint&b)const{
int i,mayor,menor;

if(dim>b.dim){
		mayor=dim,
		menor=b.dim;
	}
	else{
		mayor=b.dim,
		menor=dim;
	}
bigint*c=new bigint(mayor+1,signo);
int t,s=0;

	if(dim==mayor){
		for(i=0;i<mayor;i++){
			if(i<menor){
				s+=digitos[i]+b.digitos[i];	
				t=s%10;
				c->digitos[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
			else{
				s+=digitos[i];	
				t=s%10;
				c->digitos[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
		}
	}
	else{
		for(i=0;i<mayor;i++){
			if(i<menor){
				s+=digitos[i]+b.digitos[i];	
				t=s%10;
				c->digitos[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
			else{
				s+=b.digitos[i];	
				t=s%10;
				c->digitos[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
		}	
	}
	if(s!=0)
		c->digitos[mayor]=s;
	else
		c->dim=mayor;

return *c;
}

bigint bigint::operator-(const bigint&b)const{
			int i,mayor,menor;
			int r=0;
			bigint*c;
            if(dim>b.dim){
		mayor=dim,
		menor=b.dim;
	}
	else{
		mayor=b.dim,
		menor=dim;
	}
			if(dim==b.dim){
				if((*this)>b)
					{c=new bigint(dim,signo);
					 for(i=0;i<dim;i++)
						{if(digitos[i]+r<b.digitos[i])
								{c->digitos[i]=10+digitos[i]-b.digitos[i]+r;
								 r=-1;
								}
							else{c->digitos[i]=digitos[i]-b.digitos[i]+r;
								 r=0;
								}
						}
					}
				else{c=new bigint(b.dim,-1);
				 	for(i=0;i<b.dim;i++)
						{if(b.digitos[i]+r<digitos[i])
								{c->digitos[i]=10+b.digitos[i]-digitos[i]+r;
								 r=-1;
								}
						else{c->digitos[i]=b.digitos[i]-digitos[i]+r;
								r=0;
							}
						}
					}
				}
			else{
				if(dim==mayor)
					{c=new bigint(mayor,signo);
					 for(i=0;i<mayor;i++)
						{if(i<menor)
							{if(digitos[i]+r<b.digitos[i])
								{c->digitos[i]=10+digitos[i]-b.digitos[i]+r;
								 r=-1;
								}
							else{c->digitos[i]=digitos[i]-b.digitos[i]+r;
								 r=0;
								}
							}
						else{
							if(digitos[i]+r<0)
								{c->digitos[i]=10+digitos[i]+r;
							 	 r=-1;
								}
							else{c->digitos[i]=digitos[i]+r;
								 r=0;
								}
							}
						}
					}	
			else{c=new bigint(mayor,-1);
				 for(i=0;i<mayor;i++)
					{if(i<menor)
						{if(b.digitos[i]+r<digitos[i])
							{c->digitos[i]=10+b.digitos[i]-digitos[i]+r;
							 r=-1;
							}
						else{c->digitos[i]=b.digitos[i]-digitos[i]+r;
							 r=0;
							}
						}
					else{
						if(b.digitos[i]+r<0)
							{c->digitos[i]=10+b.digitos[i]+r;
							 r=-1;
							}
						else{c->digitos[i]=b.digitos[i]+r;
							 r=0;
							}
						}
					}
				}
			}
		i=c->dim-1;
		while(i>=1&&c->digitos[i]==0)
			{i--;
			}
		c->dim=i+1;

		return *c;	
		}
		
bigint bigint::operator%(const bigint&d)const{
		bigint*temporal=new bigint(dim,1);
		bigint*residuo=new bigint(dim,1);
		*residuo=*this;
		while(*residuo>d)
			{*temporal=*residuo;
			 *residuo=*temporal-d;
			}
			
		return *residuo;
}

bigint operator *(int n,const bigint&b){
	int i,t=0,s=0;
	bigint *c;
	c=new bigint(b.dim+1,1);
	for(int i=0;i<b.dim+1;i++){
		s+=n*b.digitos[i];
		t=s%10;
		c->digitos[i]=t;
		if(s>=10){
			s=(s-t)/10;
		}
		else{
			s=0;
		}
		
	}
	i=c->dim-1;
		while(i>=1&&c->digitos[i]==0)
			{i--;
			}
		c->dim=i+1;
	return *c;
}

bigint bigint::operator*(const bigint&b)const{
	int t;
	bigint *c;
	c=new bigint(dim*dim,1);
	for(int i=0;i<dim*dim;i++){
		c->digitos[i]=0;
	}
	if(dim>=b.dim){
	
	bigint*elementos=new bigint[b.dim];
	bigint*elem=new bigint[b.dim];
	for(int i=0;i<b.dim;i++){
		elementos[i]=b.digitos[i]*(*this);
	}
    elem[0]=elementos[0];
	for(int i=1;i<b.dim;i++){
	elem[i].dim=elementos[i].dim+i;
    }
    for(int i=1;i<b.dim;i++){
    	for(int j=0;j<elem[i].dim-i;j++){
    		elem[i].digitos[j+i]=elementos[i].digitos[j];
		}
	}
    for(int i=1;i<b.dim;i++){
    	for(int j=0;j<i;j++){
    		elem[i].digitos[j]=0;
		}
	}

	for(int i=0;i<b.dim;i++){
		*c=*c+elem[i];
	}
	t=c->dim-1;
		while(t>=1&&c->digitos[t]==0)
			{t--;
			}
		c->dim=t+1;
	if(signo!=b.signo){
		c->signo=-1;
	}
	return *c;
}
else{
	bigint*elementos=new bigint[dim];
	bigint*elem=new bigint[dim];
	for(int i=0;i<dim;i++){
		elementos[i]=digitos[i]*b;
	}
    elem[0]=elementos[0];
	for(int i=1;i<dim;i++){
	elem[i].dim=elementos[i].dim+i;
    }
    for(int i=1;i<dim;i++){
    	for(int j=0;j<elem[i].dim-i;j++){
    		elem[i].digitos[j+i]=elementos[i].digitos[j];
		}
	}
    for(int i=1;i<dim;i++){
    	for(int j=0;j<i;j++){
    		elem[i].digitos[j]=0;
		}
	}

	for(int i=0;i<dim;i++){
		*c=*c+elem[i];
	}
	t=c->dim-1;
		while(t>=1&&c->digitos[t]==0)
			{t--;
			}
		c->dim=t+1;
	if(signo!=b.signo){
		c->signo=-1;
	}
	return *c;
	
}


}


ostream& operator <<(ostream&cout,const bigint&b){
	if(b.signo<0){
		b.digitos[b.dim-1]=-1*b.digitos[b.dim-1];
	}
   for(int i=b.dim-1;i>=0;i--){
   	cout<<b.digitos[i];
   }
}

