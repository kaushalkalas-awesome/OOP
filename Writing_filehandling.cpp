#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	string data;
	//writing data into the file
	ofstream ofile;
	ofile.open("Sample.txt", ios::app);
	if(!ofile.is_open()){
		cout<<"File does not exist";
	}
	cout<<"Write anything: ";
	getline(cin,data);
	
	ofile<<data;
	ofile.close();
	return 0;
}
