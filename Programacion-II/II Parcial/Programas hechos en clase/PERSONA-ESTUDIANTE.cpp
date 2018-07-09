#include <iostream>
#include<cstring>
#include<cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class persona{
	friend ostream&operator<<(ostream&,const persona&);
	private:
	protected:
		char*nombre;
		int edad;
		char*estado_civil;
		int identidad[13];
		char sexo;
		int nivel_academico;
	
	public:
		persona();
		persona(char*,int,char*,int[],char,int);//(nombre,edad,estado_civil,identidad,sexo,nivel_acdemico)
		~persona();
		

};		


int main(int argc, char** argv) {
int Ide[]={0,8,0,1,1,9,9,8,0,0,1,3,4};	
persona P;
persona Q("Maria Jose Herrera Gutierrez",20,"Casada",Ide,'F',3);
cout<<P;
cout<<Q;

	return 0;
}

persona::persona(){
	nombre=new char[40];
	strcpy(nombre,"Jose Carlos Martinez Lopez");
	edad=23;
	estado_civil=new char[15];
	strcpy(estado_civil,"Soltero");
	for(int i=0;i<13;i++)
		identidad[i]=rand()%10;
	
	sexo='M';
	nivel_academico=4;	
}

persona::persona(char*nomb,int eda,char*ec,int ide[],char sex,int na){
	nombre=new char[40];
	strcpy(nombre,nomb);
	edad=eda;
	estado_civil=new char[15];
	strcpy(estado_civil,ec);
	for(int i=0;i<13;i++)
		identidad[i]=ide[i];
	
	sexo=sex;
	nivel_academico=na;	
}

ostream&operator<<(ostream&escribir,const persona&P){
	escribir<<"\n***********************************\n";
	escribir<<"NOMBRE: "<<P.nombre<<endl;
	escribir<<"EDAD: "<<P.edad<<endl;
	escribir<<"ESTADO CIVIL: "<<P.estado_civil<<endl;
	escribir<<"IDENTIDAD: ";
	for(int i=0;i<13;i++)
		escribir<<P.identidad[i];
	escribir<<"\nSEXO: "<<P.sexo<<endl;
	escribir<<"NIVEL ACADEMICO: ";
	switch(P.nivel_academico){
		case 1: escribir<<"Primaria\n"; break;
		case 2: escribir<<"Secundaria\n"; break;
		case 3: escribir<<"Bachillerato\n"; break;
		case 4: escribir<<"Pregrado\n"; break;
		case 5: escribir<<"Postgrado\n"; break;
		default:escribir<<"Nivel academico incorrecto\n";
		}	
return escribir;	
}

persona::~persona(){
	delete[]nombre;
	delete[]estado_civil;
	
}
