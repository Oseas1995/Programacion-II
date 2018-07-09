#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream fcin("matriz.txt",ios::in);
	if(!fcin)
		cout<<"NO se encontro el archivo\n";
	else{
	
	int**A;
	int n,m;
	fcin>>n;
	fcin>>m;
	
	A=new int*[n];	
	for(int i=0;i<n;i++)
		{A[i]=new int[i+1];
		 for(int j=0;j<i+1;j++)
		 	fcin>>A[i][j];
		}
		
		cout<<n<<endl<<m<<endl;
	for(int i=0;i<n;i++)
		{for(int j=0;j<i+1;j++)
		 	if(j==0)
			 cout<<A[i][j];
			else
			cout<<setw(4)<<A[i][j];
		cout<<endl;
		}
	ofstream fcout("Copia.txt",ios::out);
	fcout<<n<<endl<<m<<endl;
	for(int i=0;i<n;i++)
		{for(int j=0;j<i+1;j++)
		 	if(j==0)
			 	fcout<<A[i][j];
			else
				fcout<<setw(4)<<A[i][j];
		fcout<<endl;
		}
}
	return 0;
}
