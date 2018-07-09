#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cmath>
using namespace std;

typedef unsigned int uint;
class bigint{
	protected:
		uint longitud;
		int signo;
		int*d;
	public:
		bigint();
		bigint(uint,int);
		~bigint();
		virtual void Imprimir()const;
		bool operator>(bigint&)const;
		virtual bigint&operator+(bigint&)const;  
		virtual bigint&operator-(bigint&)const;
	//	virtual bigint&operator*(bigint&)const;
		
		
		
}; 

class bigintbaseb:public bigint{  
     
 protected : 
 int base ;   

 public :  
 bigintbaseb(){ 
 bigint(); 
 base=2; 
  
 }  
 bigintbaseb ( uint  , int , int  ); 
  
 bigintbaseb*operator+(bigintbaseb&)const ; 
 bigintbaseb*operator-(bigintbaseb&)const ; 
 bigintbaseb*operator%(bigintbaseb&)const ;          
 bigintbaseb*operator*(bigintbaseb&)const ;   
 };  
 
class polinomio:public bigintbaseb{
	
	 public: 
 
  polinomio();
  polinomio(uint); 
  ~polinomio(); 
  virtual void imprimir()const;
  void imprimirmultiplicacion(polinomio &q)const;
  virtual polinomio* operator+(const polinomio &q);
  virtual polinomio* operator-(const polinomio &q);
  polinomio* operator*(const polinomio &q); 
      
 protected: 
  uint grado; 
  float *c;
	
	
};
uint Mayor(uint a,uint b){
	if(a>b)
		return a;
	else
		return b;
}

int main(int argc, char** argv) {
	//acciones de la calse bigint
	
	
	uint L1,L2,n1,n2,base=10;
	cout<<"Ingrese la longitud del numero a=";
	cin>>L1;
	cout<<"Ingrese la longitud del numero b=";
	cin>>L2;
	//cout<<"Ingrese la base: ";
	//cin>>base;
	cout<<"******************************************Operaciones bajo base "<<base<<"******************************************";
	bigintbaseb a(L1,base,1),b(L2,base,1);
	cout<<"\na=";
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
	bigint*sbigint=a+b;
	sbigint->Imprimir();
	cout<<"\na-b=";
	bigint*rbigint=a-b;
	rbigint->Imprimir();
	bigint*modbigint=a%b;
	cout<<"\na%b=";
	modbigint->Imprimir();
	delete sbigint,rbigint,modbigint;
	
	//acciones de la clase polinomio
	
n1=L1-1;
n2=L2-1;
	cout<<"\n\n";
polinomio p(n1), q(n2); 
cout<<"******************************************Polinomios******************************************\n\n"; 
cout<<"El grado del polinomio p: "<<n1<<endl;
cout<<"El grado del polinomio q: "<<n2<<endl;
cout<<"\n\nPolinomio p: "; 
p.imprimir(); 
cout<<"Polinomio q: "; 
q.imprimir();   

polinomio*spolinomio=p+q; 
cout<<"La Suma de polinomios p+q= "; 
spolinomio->imprimir(); 

cout<<"La Resta de polinomios "; 
polinomio *rpolinomio=p-q;
rpolinomio->imprimir();

cout<<"La Multiplicacion de polinomios p*q= ";
polinomio *multipolinomio= p*q;
multipolinomio->imprimir();

delete spolinomio ,rpolinomio,multipolinomio;
	
	
	return 0;
}

//Funciones de la clase bigint
	bigint::bigint(){
		longitud=1;
		signo=1;
		d=new int[longitud];
		d[0]=0;
		
	}
	
	bigint::bigint(uint l,int s){
		longitud=l;
		signo=1;
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
bigint&bigint::operator+(bigint&b)const{
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

return *c;

			
		}
bigint&bigint::operator-(bigint&b)const{
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

		return *c;	
		}
 
	

bigintbaseb::bigintbaseb ( uint l , int b, int s ){
		longitud=l;
		base=b;
		signo=1;
		d=new int[longitud];
		for(int i=0;i<longitud-1;i++)
		    d[i]=rand()%base;
		d[longitud-1]=1+rand()%(base-1);
	   	
	}

bigintbaseb* bigintbaseb :: operator+(bigintbaseb&b) const{ 
	   uint i ,mayor , menor ; 
	   mayor=Mayor( longitud ,b.longitud );
	   menor=longitud+b.longitud-mayor ;
	   bigintbaseb*c=new bigintbaseb (mayor+1,base,signo ); 
	   int t ,s=0; 
	   if ( longitud==mayor){ 
	      for ( i =0;i<mayor ; i++){ 
		       if ( i<menor){
			      s+=d[i]+b.d[ i ] ; 
				  t=s%base; 
				  c->d[i]=t ; 
				  if ( s==t ) 
				      s=0; 
				  else 
				      s=1; 
				}
				else{ 
				  s+=d[ i ] ; 
				  t=s%base; 
				  c->d[ i ]=t ; 
				  if ( s==t ) 
				      s=0; 
				  else 
				      s=1; 
				} 
			} 
		} 
		else{
		   for ( i =0;i<mayor ; i++){ 
		        if ( i<menor){ 
				    s+=d[ i ]+b.d[ i ] ; 
					t=s%base; 
					c->d[ i ]=t ; 
					if ( s==t ) 
					    s=0; 
					else 
					    s=1; 
				} 
				else{ 
				    s+=b.d[ i ] ; 
					t=s%base;
					c->d[ i ]=t ; 
					if ( s==t ) 
					    s=0; 
					else 
					     s=1; 
					} 
			} 
		} 
		if( s!=0) 
		    c->d[ mayor]=s ;
		else 
		    c->longitud=mayor ; 
		return c ; 
	} 
	
bigintbaseb*bigintbaseb :: operator-(bigintbaseb&b) const{  
    uint i ,mayor , menor ; 
    int r=0;  
    bigintbaseb*c ;  
    mayor=Mayor( longitud ,b.longitud );  
    menor=longitud+b.longitud-mayor ;  
    if ( longitud==b.longitud ){  
        if ((* this)>b) 
     {c=new bigintbaseb ( longitud ,base, signo );  
      for ( i =0;i<longitud ; i++) 
     {if (d[ i ]+r<b.d[ i ])  
        {c->d[ i]=base+d[ i]-b.d[ i ]+r ; 
      r=-1;  
     }  
      else{c->d[ i ]=d[ i]-b.d[ i ]+r ;  
           r=0; 
    }  
   }  
     }  
     else{c=new bigintbaseb (b.longitud ,base,-1);  
     for ( i =0;i<b. longitud ; i++)  
        {  if (b.d[ i ]+r<d[ i ])  
        {c->d[ i]=base+b.d[ i]-d[ i ]+r ;  
      r=-1;  
     }  
     else{c->d[ i ]=b.d[ i]-d[ i ]+r ;  
         r=0;  
      }  
    }  
     }  
  }  
  else{  
      if ( longitud==mayor){ 
       c=new bigintbaseb (mayor ,base, signo );  
    for ( i =0;i<mayor ; i++) { 
        if ( i<menor) { 
         if (d[ i ]+r<b.d[ i ]) { 
          c->d[ i]=base+d[ i]-b.d[ i ]+r ;  
       r=-1; 
       }  
      else{c->d[ i ]=d[ i]-b.d[ i ]+r ; 
      r=0; 
      } 
     } 
     else{  
         if (d[ i ]+r<0) { 
         c->d[ i]=base+d[ i ]+r ;  
         r=-1;  
      }  
      else{c->d[ i ]=d[ i ]+r ;  
      r=0;  
      }  
     }  
    }  
   }  
   else{ 
    c=new bigintbaseb (mayor,base,-1); 
    for ( i =0;i<mayor ; i++) { 
        if ( i<menor) { 
        if (b.d[i]+r<d[i]){ 
         c->d[ i]=base+b.d[ i]-d[ i ]+r ;  
      r=-1;  
     } 
     else{c->d[ i ]=b.d[ i]-d[ i ]+r ; 
         r=0; 
      }  
    }  
    else{  
        if (b.d[ i ]+r<0) { 
        c->d[ i]=base+b.d[ i ]+r ; 
        r=-1;  
     }  
     else{c->d[ i ]=b.d[ i ]+r ;  
        r=0;  
     }  
    }  
    }  
     }  
  }  
  i=c->longitud -1;  
  while ( i>=1&&c->d[ i ]==0) 
  {i--;  
  }  
  c->longitud=i +1;  
        return c ; 
 }  
  
 bigintbaseb*bigintbaseb :: operator%(bigintbaseb&d) const{  
     bigintbaseb*temporal=new bigintbaseb ( longitud ,base,1);  
  bigintbaseb*residuo=new bigintbaseb ( longitud ,base,1);  
  *residuo=*this ;  
  while (*residuo>d)  
  {*temporal=*residuo ;  
   residuo=*temporal-d;  
  }  
  return residuo ;  
 } 
	bigintbaseb*bigintbaseb::operator *(bigintbaseb&b)const{
		int binario[20];
		int temp1=0,temp2=0;
		uint i=0;
		
		for(uint i=0; i<longitud; i++){
			temp1=temp1+d[i]*pow(2,i);
		}
		for(uint i=0; i<b.longitud; i++){
			temp2=temp2+b.d[i]*pow(2,i);
		}
		int p=temp1*temp2;
		for(uint i=0; i<b.longitud-1; i++){
			p=p+d[i]*pow(10,i);
		}
		while (p>=2){
			binario[i]=p%2;
			p=p/2;
			i++;
				
		}
		binario[i]=p;
		for(uint j=i;j>0;j--)
		cout<<binario[i];
		cout<<binario[0];
	}
	//funciones de la clase polinomio
	
polinomio::polinomio(){ 
 grado=0; 
 c=new float[1]; 
 c[0]=0; 
}  
polinomio::polinomio(uint n){
 grado=n;
 c=new float[grado+1]; 
  
 for(uint i=0;i<grado;i++) 
  {c[i]=rand()%10;
  } 
 c[grado]=1+rand()%9; 
}  

polinomio::~polinomio(){
  
 delete[]c; 
}   
void polinomio::imprimir()const{  
 for(uint i=grado;i>=1;i--) 
  cout<<c[i]<<"x^"<<i<<"+"; 
  
 cout<<c[0]<<"\n\n\n"; 
} 

uint mayor(uint n,uint m){ 
 if(n>m) 
  return n; 
 else 
  return m; 
}  
polinomio*polinomio::operator+(const polinomio&q){ 
 uint M=mayor(grado,q.grado); 
 uint m=grado+q.grado-M; 
 polinomio *s=new polinomio(M); 
 if(grado==M)
  {for(uint i=0;i<=M;i++) 
   {if(i<=m) 
    s->c[i]=c[i]+q.c[i]; 
    
    else   
    s->c[i]=c[i]; 
   } 
  } 
 else{ 
  for(uint i=0;i<=M;i++) 
   {if(i<=m) 
    s->c[i]=c[i]+q.c[i]; 
    
    else   
    s->c[i]=q.c[i]; 
   } 
 } 
polinomio *ptrq=s; 
 return ptrq; 
}  

polinomio*polinomio::operator-(const polinomio&q){
	
	int M= Mayor(grado, q.grado);
	int m= grado + q.grado-M;
	polinomio *s=new polinomio(M);
	if(grado==M && q.grado!=M){ 
	    cout<<"p-q es: \n\n";
	    for(int i=0; i<M;i++){ 
	        if(i<=m){ 
		       if(c[i]<q.c[i] ||c[i]>q.c[i]){ 
		          s->c[i]=c[i]-q.c[i];
			      
		       }   
			   else
			      s->c[i]=0; 
			   
           }
           
    	}
    	s->c[M]=c[M];
    	
    }
   else
    if(q.grado==M && grado!=M ){ 
      cout<<"q-p es: \n\n";
      for(int i=0; i<M;i++){ 
	        if(i<=m){ 
		       if(q.c[i]<c[i] ||q.c[i]>c[i]){ 
		          s->c[i]=q.c[i]-c[i];
			     
		       }   
			   else 
			      s->c[i]=0; 
			    
           }
           s->c[M]=q.c[M];
           
    	}
    
   } 
   else {
   
      if(grado==M && q.grado==M) {
        for(int i=0; i<=M;i++){
        	if(c[M]>q.c[M]){
			
		       s->c[i]=c[i]-q.c[i];   
		    }
            else{
			   
		       s->c[i]=c[i]-q.c[i];
		   }
    	}
    	
    
	  }
}
return s; 

}

//Multiplicacion de pol

polinomio*polinomio::operator*(const polinomio &q){
	int grado1=grado, grado2=q.grado;
	int m=grado1+grado2;
	 polinomio *mul=new polinomio(m);
	for (int k = 0; k < grado1 + grado2 + 1; k++)
            mul->c[k] = 0;
	for (int i = 0; i < grado1 + 1; i++)
            for (int j = 0; j < grado2 + 1; j++){
                mul->c[i+j] += c[i] * q.c[j];
            }
            
	for (int z = 0; z < grado1 + 1; z++)
            for (int w = 0; w < grado2 + 1; w++){
                mul->c[z+w] += c[z] * q.c[w];
            }	 
    for (int f = 0; f <= grado1+grado2; f++){
                mul->c[f] = (mul->c[f])/2;
            }	 

    return mul;
}



