#include <iostream>
#include <new>
#include <cstring>
#include<cstdlib>
using std::bad_alloc;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
int main(int argc, char** argv) {
try{
int*ptr=new int[10];
}
catch(bad_alloc&error_asignacion){
	cout<<"ERROR: Insuficiente memoria para asignar\n";
	cout<<error_asignacion.what()<<endl;
}

char**grupos=new char*[5];
for(int i=0;i<5;i++)
	grupos[i]=new char[15];
	
strcpy(grupos[0],"Sohari");
strcpy(grupos[1],"Pedro");
strcpy(grupos[2],"Abner");
strcpy(grupos[3],"Sandra");
strcpy(grupos[4],"Gaby");


char**asignacion=new char*[5];
for(int i=0;i<5;i++)
	{asignacion[i]=new char[15];
	 asignacion[i]=NULL;
	}

int k,i=0;	
while(i<5){
	do{
	k=rand()%5;
	}
	while(asignacion[k]!=NULL);
	asignacion[k]=grupos[i];
	i++;
}	

for(int i=0;i<5;i++){
	cout<<i+1<<"->"<<asignacion[i]<<endl;
}
	return 0;
}
