#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	string data;
	
	//writing data into the file
	ofstream ofile;
	ofile.open("Sample.txt");
	if(!ofile.is_open()){
		cout<<"File does not exist";
	}
	cout<<"Write anything: ";
	getline(cin,data);
	
	ofile<<data;
	ofile.close();
	
	//Reading data from the file
	ifstream ifile;
	ifile.open("Sample.txt");
	string read;
	if(!ifile.is_open()){
		cout<<"File does not exist";
		exit(0);
	}
	cout<<"\nContent of the file: ";
	while(getline(ifile,read)){
		cout<<read<<endl;
	}
	
	ifile.close();
	
	return 0;
}
