#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	string read;
	//Reading data from the file
	ifstream ifile;
	ifile.open("Sample.txt");
	if(!ifile.is_open()){
		cout<<"File does not exist";
		exit(0);
	}
	cout<<"\nContent of the file: \n";
	while(getline(ifile,read)){
		cout<<read<<endl;
	}
	
	ifile.close();
	return 0;
}
