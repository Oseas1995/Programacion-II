#include <iostream>
#include<cstdlib>

using namespace std;
using std::cin;
using std::endl;
using std::cout;
using std::cerr;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float division(float a, float b){
	if(b==0)
		throw b;
	else
		return a/b;
}



int main(int argc, char** argv) {
	int a,b;
	cout<<"a=";cin>>a;
	cout<<"b=";cin>>b;
	try{
		cout<<a<<"/"<<b<<"= "<<division(a,b)<<endl;
	}
	catch(float error){
		cerr<<"la division entre cero no esta definido\n";
	}
	system("pause");
	return 0;
}
