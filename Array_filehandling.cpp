#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter No. of Students: ";
	cin>>n;
	string student[n];
	
	for(int i=0;i<n;i++){
		cout<<"\nEnter Student Name: "<<endl;
		fflush(stdin);
		getline(cin,student[i]);
	}
	
	cout<<"\nName of Students: ";
	for(int i=0;i<n;i++){
		cout<<student[i]<<endl;
	}
	
	fstream file("Student.txt", ios::app);
	for(int i=0;i<n;i++){
		file<<(i+1)<<". "<<student[i]<<endl;
	}
	
	return 0;
}
