#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class matriz{
	friend ostream& operator<<(ostream&,const matriz&);
	friend matriz* operator-(const matriz&, const matriz&);
	friend matriz* operator*(float, const matriz&);
	private:
		int nFilas, nColumnas;
		float **elementos;
	public:
		matriz();
		matriz(int, int);
		~matriz();
		matriz* operator+(const matriz&)const;
		matriz* operator*(const matriz&)const;
		matriz* transpuesta();
		void esSimetrica();
		bool operator==(const matriz&)const;
		
};

int main(int argc, char** argv) {
	srand(time(0));
	cout<<"MATRIZ M:\n";
	matriz m(3,3);
	cout<<m;
	cout<<"MATRIZ Z CON EL CONSTRUCTOR POR DEFECTO:\n";
	matriz z;
	cout<<z;
	cout<<"MATRIZ Z1 CON EL CONSTRUCTOR POR DEFECTO:\n";
	matriz z1;
	cout<<z1;
	
	cout<<"MATRIZ M1:\n";
	matriz m1(3,3);
	cout<<m1;
	
	cout<<"LA MATRIZ M1 ";
	m1.esSimetrica();
	
	cout<<"TRANSPUESTA DE M1:\n";
    cout<<*(m1.transpuesta());
	
	return 0;
}

matriz::matriz(){
	nFilas=2;
	nColumnas=2;
	elementos = new float*[nFilas];
	for(int i=0;i<nFilas;i++)
			elementos[i] = new float[nColumnas];
	for(int i=0;i<nFilas;i++)
		for(int j=0;j<nColumnas;j++)
			elementos[i][j]=1;
}

matriz::matriz(int f, int c){
	nFilas=f;
	nColumnas=c;
	elementos = new float*[nFilas];
	for(int i=0;i<nFilas;i++)
			elementos[i] = new float[nColumnas];
	for(int i=0;i<nFilas;i++)
		for(int j=0;j<nColumnas;j++)
			elementos[i][j]=rand()%10;
	
}

ostream& operator<<(ostream& escribir,const matriz& m){
	
	for(int i=0;i<m.nFilas;i++){
		for(int j=0;j<m.nColumnas;j++)
			escribir<<m.elementos[i][j]<<" ";
		cout<<"\n\n";
	}	
		
	escribir;
}

matriz::~matriz(){
	for(int i=0;i<nFilas;i++){
		delete[] elementos[i];
	}
	delete[] elementos;
}

matriz* matriz::operator+(const matriz& m)const{
	if(nFilas==m.nFilas && nColumnas==m.nColumnas){
		matriz *sum = new matriz(m.nFilas, m.nColumnas);
		for(int i=0;i<nFilas;i++)
			for(int j=0;j<nColumnas;j++)
				sum->elementos[i][j]=elementos[i][j]+m.elementos[i][j];
			
		return sum;
	}else{
		return NULL;
	}
	
}

matriz* operator-(const matriz& m1, const matriz& m2){
	if(m1.nFilas==m2.nFilas && m1.nColumnas==m2.nColumnas){
		matriz *res = new matriz(m1.nFilas, m1.nColumnas);
		for(int i=0;i<(res->nFilas);i++)
			for(int j=0;j<(res->nColumnas);j++)
				res->elementos[i][j]=m1.elementos[i][j]-m2.elementos[i][j];
			
		return res;
	}else{
		return NULL;
	}
	
}

matriz* matriz::operator*(const matriz& m)const{
	if(nColumnas==m.nFilas){
		matriz *mul = new matriz(nFilas, m.nColumnas);
		for(int i=0;i<(mul->nFilas);i++)
			for(int j=0;j<(mul->nColumnas);j++)
				mul->elementos[i][j]=0;
		
		for(int i=0;i<(mul->nFilas);i++)
			for(int j=0;j<(mul->nColumnas);j++)
				for(int k=0;k<(mul->nColumnas);k++)
					mul->elementos[i][j]+=elementos[i][k]*m.elementos[k][j];	
		
			
		return mul;
	}else{
		return NULL;
	}
}

matriz* operator*(float k, const matriz& m){
	matriz *mul = new matriz(m.nFilas, m.nColumnas);
		for(int i=0;i<(mul->nFilas);i++)
			for(int j=0;j<(mul->nColumnas);j++)
				mul->elementos[i][j]=k*m.elementos[i][j];
	return mul;
}

matriz* matriz::transpuesta(){
	matriz *t=new matriz(nFilas,nColumnas);
	for(int i=0;i<(nColumnas);i++){
		for(int j=0;j<(nFilas);j++)
		    t->elementos[i][j]=elementos[j][i];
		
	}
	return t;			
}

bool matriz::operator==(const matriz& m)const{
	bool resp= false;
	if(nFilas==nColumnas && nColumnas==m.nFilas && m.nFilas==m.nColumnas){	
		for(int i=0;i<nFilas;i++)	
			for(int j=0;j<nFilas;j++)
				if(elementos[i][j]==m.elementos[i][j]){
					resp=true;
				}else{
					resp=false;
					break;
				}
	}
	return resp;
}

void matriz::esSimetrica(){
	if(*this == *(this->transpuesta())){
		cout<<"Es Simetrica.\n\n";
	}else{
		cout<<"No es simetrica.\n\n";
	}
}







