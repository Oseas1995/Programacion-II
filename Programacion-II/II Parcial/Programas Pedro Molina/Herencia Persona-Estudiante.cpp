#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class persona{
	friend ostream& operator <<(ostream&,const persona&);
	protected:
		char*nombre;
		int edad;
		char sexo;
		int identidad[13];
		char*estado_civil;
	public:
		persona();
		persona(char*,int,char,char*);
		
		
};

class estudiante:public persona{
	friend ostream& operator <<(ostream&,const estudiante&);
	private:
		int cuenta[11];
		char*carrera;
		float indice;
	public:
		estudiante();
		estudiante(char*,int,char,char*,char*,float);
		
};

int main(){
	persona P;
	cout<<P;
	persona Q("Nahomy Maudruely Ortiz Lagos",18,'M',"Soltera");
	cout<<Q;
	estudiante E;
	cout<<E;
	estudiante A("Nahomy Maudruely Ortiz Lagos",18,'M',"Soltera","Biologia",74);
	cout<<A;
	
	return 0;
}

persona::persona(){
	nombre=new char[40];
	strcpy(nombre,"Jose Carlos Lovo Sosa");
	edad=23;
	sexo='H';
	for(int i=0;i<13;i++){
		identidad[i]=rand()% 10;
	}
	estado_civil=new char[15];
	strcpy(estado_civil,"Divorciado");
}

persona::persona(char*nomb,int n,char sex,char*ec){
	nombre=new char[40];
	strcpy(nombre,nomb);
	edad=n;
	sexo=sex;
	for(int i=0;i<13;i++){
		identidad[i]=rand()% 10;
	}
	estado_civil=new char[15];
	strcpy(estado_civil,ec);
	
}

estudiante::estudiante(){
	nombre=new char[40];
	strcpy(nombre,"Pedro Jose Molina Morales");
	edad=20;
	sexo='H';
    for(int i=0;i<13;i++){
    	identidad[i]=rand()% 10;
	}
	//identidad[13]={0,7,0,4,1,9,9,8,0,0,7,0,2};
	estado_civil=new char[15];
	strcpy(estado_civil,"Soltero");
//	cuenta[11]={2,0,1,6,1,0,0,1,7,6,7};
	for(int i=0;i<11;i++){
		cuenta[i]=rand()% 10;
	}
	carrera=new char[40];
	strcpy(carrera,"Matematicas");
	indice=94;
}

estudiante::estudiante(char*nomb,int n,char sex,char*ec,char*ca,float ind){
	nombre=new char[40];
	strcpy(nombre,nomb);
	edad=n;
	sexo=sex;
	for(int i=0;i<13;i++){
		identidad[i]=rand()% 10;
	}
	estado_civil=new char[15];
	strcpy(estado_civil,ec);
	for(int i=0;i<11;i++){
		cuenta[i]=rand()% 10;
	}
	carrera=new char[40];
	strcpy(carrera,ca);
	indice=ind;
}



ostream& operator <<(ostream&cout,const persona&P){
	cout<<"****************************************"<<endl;
	cout<<"NOMBRE: "<<P.nombre<<endl;
	cout<<"EDAD: "<<P.edad<<endl;
	cout<<"SEXO: "<<P.sexo<<endl;
	cout<<"IDENTIDAD: ";
	for(int i=0;i<13;i++){
		cout<<P.identidad[i];
	}
	cout<<"\nESTADO CIVIL: "<<P.estado_civil<<endl;
	return cout;
}

ostream& operator <<(ostream&cout,const estudiante&E){
	cout<<"****************************************"<<endl;
	cout<<"NOMBRE: "<<E.nombre<<endl;
	cout<<"EDAD: "<<E.edad<<endl;
	cout<<"SEXO: "<<E.sexo<<endl;
	cout<<"IDENTIDAD: ";
	for(int i=0;i<13;i++){
		cout<<E.identidad[i];
	}
	cout<<"\nESTADO CIVIL: "<<E.estado_civil<<endl;
	cout<<"CUENTA: ";
	for(int i=0;i<11;i++){
		cout<<E.cuenta[i];
	}
	cout<<"\nCARRERA: "<<E.carrera<<endl;
	cout<<"INDICE: "<<E.indice<<endl;
	return cout;
}
