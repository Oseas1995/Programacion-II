
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef unsigned int uint;
class bigint{
	private:
		uint longitud;
		int signo;
		int*d;
	public:
		bigint();
		bigint(uint,int);
		~bigint();
		void Imprimir()const;
		bool operator>(bigint&)const;
		bigint*operator+(bigint&)const;
		bigint*operator-(bigint&)const;
		bigint*operator%(bigint&)const;
		
};

uint Mayor(uint a,uint b){
	if(a>b)
		return a;
	else
		return b;
}

int main(int argc, char** argv) {
	srand(time(0));
	uint L1,L2;
	cout<<"ingrese la longitud del numero a=";
	cin>>L1;
	cout<<"ingrese la longitud del numero b=";
	cin>>L2;
	bigint a(L1,1),b(L2,1);
	cout<<"a=";
	a.Imprimir();
	cout<<"\nb=";
	b.Imprimir();
	cout<<endl;
	a.Imprimir();
	if(a>b)
	cout<<" es Mayor que ";
	else
	cout<<" es Menor que ";
	b.Imprimir();
	
	cout<<"\na+b=";
	bigint*s=a+b;
	s->Imprimir();
	cout<<"\na-b=";
	bigint*r=a-b;
	r->Imprimir();
	bigint*m=a%b;
	cout<<"\na%b=";
	m->Imprimir();
	delete s,r,m;
	
	return 0;
}

	bigint::bigint(){
		longitud=1;
		signo=1;
		d=new int[longitud];
		d[0]=0;
		
	}
	bigint::bigint(uint l,int s){
		longitud=l;
		signo=s;
		d=new int[longitud];
		for(int i=0;i<longitud-1;i++)
			d[i]=rand()%10;
		d[longitud-1]=1+rand()%9;
	}
	bigint::~bigint(){
		delete[]d;
		
	}
	void bigint::Imprimir()const{
		if(longitud==1)
			cout<<signo*d[0];
		else{
			cout<<signo*d[longitud-1];
		for(uint i=longitud-2;i>=1;i--)
			cout<<d[i];
		cout<<d[0];
		}
		
		}
		
	bool bigint::operator>(bigint&n)const{
		if(signo>n.signo)
			return true;
		else
			if(signo<n.signo)
				return false;
			else
				if(signo>0)
					{if(longitud>n.longitud)
						return true;
					else
						if(longitud<n.longitud)
							return false;
						else{
							bool resp=true;
							uint i=longitud-1;
							while(i>=1&&d[i]==n.d[i])
								{i--;
								}
								
								if(d[i]>n.d[i])
									resp=true;
								else
									resp=false;
									
							return resp;
						}
					}
				else{
					if(longitud<n.longitud)
						return true;
					else
						if(longitud>n.longitud)
							return false;
						else{
							bool resp=true;
							uint i=longitud-1;
							while(i>=1&&d[i]==n.d[i])
								{	i--;
								}
								
								if(d[i]<n.d[i])
									resp=true;
								else
									resp=false;
									
							return resp;
						}
					}	
	}
bigint*bigint::operator+(bigint&b)const{
uint i,mayor,menor;
	
mayor=Mayor(longitud,b.longitud);
menor=longitud+b.longitud-mayor;
bigint*c=new bigint(mayor+1,signo);
int t,s=0;

	if(longitud==mayor){
		for(i=0;i<mayor;i++){
			if(i<menor){
				s+=d[i]+b.d[i];	
				t=s%10;
				c->d[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
			else{
				s+=d[i];	
				t=s%10;
				c->d[i]=t;
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
				s+=d[i]+b.d[i];	
				t=s%10;
				c->d[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
			else{
				s+=b.d[i];	
				t=s%10;
				c->d[i]=t;
				if(s==t)
					s=0;
				else
					s=1;
			}	
		}	
	}
	if(s!=0)
		c->d[mayor]=s;
	else
		c->longitud=mayor;

return c;

			
		}
bigint*bigint::operator-(bigint&b)const{
			uint i,mayor,menor;
			int r=0;
			bigint*c;
			mayor=Mayor(longitud,b.longitud);
			menor=longitud+b.longitud-mayor;
			if(longitud==b.longitud){
				if((*this)>b)
					{c=new bigint(longitud,signo);
					 for(i=0;i<longitud;i++)
						{if(d[i]+r<b.d[i])
								{c->d[i]=10+d[i]-b.d[i]+r;
								 r=-1;
								}
							else{c->d[i]=d[i]-b.d[i]+r;
								 r=0;
								}
						}
					}
				else{c=new bigint(b.longitud,-1);
				 	for(i=0;i<b.longitud;i++)
						{if(b.d[i]+r<d[i])
								{c->d[i]=10+b.d[i]-d[i]+r;
								 r=-1;
								}
						else{c->d[i]=b.d[i]-d[i]+r;
								r=0;
							}
						}
					}
				}
			else{
				if(longitud==mayor)
					{c=new bigint(mayor,signo);
					 for(i=0;i<mayor;i++)
						{if(i<menor)
							{if(d[i]+r<b.d[i])
								{c->d[i]=10+d[i]-b.d[i]+r;
								 r=-1;
								}
							else{c->d[i]=d[i]-b.d[i]+r;
								 r=0;
								}
							}
						else{
							if(d[i]+r<0)
								{c->d[i]=10+d[i]+r;
							 	 r=-1;
								}
							else{c->d[i]=d[i]+r;
								 r=0;
								}
							}
						}
					}	
			else{c=new bigint(mayor,-1);
				 for(i=0;i<mayor;i++)
					{if(i<menor)
						{if(b.d[i]+r<d[i])
							{c->d[i]=10+b.d[i]-d[i]+r;
							 r=-1;
							}
						else{c->d[i]=b.d[i]-d[i]+r;
							 r=0;
							}
						}
					else{
						if(b.d[i]+r<0)
							{c->d[i]=10+b.d[i]+r;
							 r=-1;
							}
						else{c->d[i]=b.d[i]+r;
							 r=0;
							}
						}
					}
				}
			}
		i=c->longitud-1;
		while(i>=1&&c->d[i]==0)
			{i--;
			}
		c->longitud=i+1;

		return c;	
		}
		
		bigint*bigint::operator%(bigint&d)const{
		bigint*temporal=new bigint(longitud,1);
		bigint*residuo=new bigint(longitud,1);
		*residuo=*this;
		while(*residuo>d)
			{*temporal=*residuo;
			 residuo=*temporal-d;
			}
			
		return residuo;
		
		}
