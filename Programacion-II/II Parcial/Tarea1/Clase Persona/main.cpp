#include <iostream>
#include <cstring>

using namespace std;

// INICIO DE LA CLASE PERSONA

class persona{
	friend ostream& operator<<(ostream&, const persona&);
	
	private:
	protected:
		char* nombre;
		int edad;
		char sexo;
		char* identidad;
		char* estado_civil;
		
		
	public:
		persona(){
			nombre = new char[40];
			strcpy(nombre, "Juan Carlos Martinez Lopez");
			edad=23;
			sexo='M';
			identidad = new char[15];
			strcpy(identidad, "0801-1994-15348");
			estado_civil = new char[15];
			strcpy(estado_civil, "Soltero");
			
		}
		persona(char* nomb, int eda, char sex, char* ident, char* ec){//(nombre, edad, sexo, identidad, estado_civil)
			nombre = new char[40];
			strcpy(nombre, nomb);
			edad=eda;
			sexo=sex;
			identidad = new char[15];
			strcpy(identidad, ident);
			estado_civil = new char[15];
			strcpy(estado_civil, ec);
		}
		~persona();
		void poner_nombre(char*);
		void poner_edad(int);
		void poner_sexo(char);
		void poner_identidad(char*);
		void poner_estado_civil(char*);
		
};
// FIn DE LA CLASE PERSONA


// INICIO DE LA CLASE ESTUDIANTE
class estudiante: public persona{
	friend ostream& operator<<(ostream&, const estudiante&);
	
	private:
		char* cuenta;
		char* carrera;
		int indice;
				
	public:
		
		estudiante(char*, int, char, char*, char*, char*, int);//nombre, edad, sexo, identidad, cuenta, carrera, indice
		void poner_cuenta(char*);
		void poner_carrera(char*);
		void poner_indice(int);
		void adicionar_clase();
		void cancelar_clase();
};
// FIN DE LA CLASE ESTUDIANTE


// INICIO DE FUNCIONES DE LA CLASE PERSONA
persona::~persona(){
	delete[] nombre;
	delete[] identidad;
	delete[] estado_civil;
}

ostream& operator<<(ostream& escribir, const persona& p){
	escribir<<"*************************************"<<endl;
	escribir<<"Nombre: "<<p.nombre<<endl;
	escribir<<"Edad: "<<p.edad<<endl;
	escribir<<"Sexo: "<<p.sexo<<endl;
	escribir<<"Identidad: "<<p.identidad<<endl;
	escribir<<"Estado Civil: "<<p.estado_civil<<endl;
}

void persona::poner_nombre(char* nomb){
	nombre = new char[40];
	strcpy(nombre, nomb);
}

void persona::poner_edad(int eda){
	edad = eda;
}
void persona::poner_sexo(char sex){
	sexo = sex;
}
void persona::poner_identidad(char* ident){
	identidad = new char[15];
	strcpy(identidad, ident);
}
void persona::poner_estado_civil(char* ec){
	estado_civil = new char[15];
	strcpy(estado_civil, ec);
}

// FIN DE FUNCIONES DE LA CLASE PERSONA


// INICIO DE FUNCIONES DE LA CLASE ESTUDIANTE

estudiante::estudiante(char* nomb, int eda, char sex, char* ident, char* cuent, char* carrer, int indic){
	nombre = new char[40];
	strcpy(nombre, nomb);
	edad = eda;
	sexo = sex;
	identidad = new char[15];
	strcpy(identidad, ident);
	cuenta = new char[20];
	strcpy(cuenta, cuent);
	carrera = new char[30];
	strcpy(carrera, carrer);
	indice = indic;
}

ostream& operator<<(ostream& escribir, const estudiante& e){
	escribir<<"*************************************"<<endl;
	escribir<<"Nombre: "<<e.nombre<<endl;
	escribir<<"Edad: "<<e.edad<<endl;
	escribir<<"Sexo: "<<e.sexo<<endl;
	escribir<<"Identidad: "<<e.identidad<<endl;
	escribir<<"Cuenta: "<<e.cuenta<<endl;
	escribir<<"Carrera: "<<e.carrera<<endl;
	escribir<<"Indice: "<<e.indice<<"%"<<endl;
}

void estudiante::poner_cuenta(char* cuent){
	cuenta = new char[20];
	strcpy(cuenta, cuent);
}

void estudiante::poner_carrera(char* carrer){
	carrera = new char[30];
	strcpy(carrera, carrer);
}

void estudiante::poner_indice(int indic){
	indice = indic;
}

void estudiante::adicionar_clase(){
	cout<<"*************************************"<<endl;
	char* clase = new char[40];
	cout<<"Ingrese la asignatura que desea adicionar: ";
	cin>>clase;
	cout<<"La clase "<<clase<<" fue adicionada con exito!!\n"<<endl;
}

void estudiante::cancelar_clase(){
	cout<<"*************************************"<<endl;
	char* clase = new char[40];
	cout<<"Ingrese asignatura que desea cancelar: ";
	cin>>clase;
	cout<<"La clase "<<clase<<" fue cancelada con exito!!\n"<<endl;
}
// FIN DE FUNCIONES DE LA CLASE ESTUDIANTE


int main(int argc, char** argv) {
	//Objetos de la clase persona
	persona p;
	persona p1("Maria Jose Perez Martinez",20, 'F',"0801-1998-12345","Soltera");
	
	//Metodos de la clase persona
	p.poner_nombre("Pedro Pablo Raudales");
	p.poner_edad(23);
	p.poner_identidad("0801-1996-12345");
	p.poner_estado_civil("Casado");
	
	cout<<p;
	cout<<p1;
	
	//objeto de la clase estudiante
	estudiante e("Juan Carlos Martinez", 24, 'M', "0801-1994-12345", "12345678", "Lic. matematicas", 70);
	cout<<e;
	
	//Metodos de la clase estudiante
	e.poner_nombre("David Hernandez");
	e.poner_edad(20);
	e.poner_cuenta("2121212121");
	e.poner_indice(81);
	cout<<e;
	
	e.adicionar_clase();
	e.cancelar_clase();
	
	//Manipuladores
	persona &refe = e;
	refe.poner_nombre("Miguel Antonio Aguilar");
	refe.poner_edad(35);
	refe.poner_sexo('M');
	refe.poner_identidad("0801-1983-54321");
	refe.poner_estado_civil("Divorciado");
	cout<<refe;
	
	return 0;
}

