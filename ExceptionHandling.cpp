//Exception handling
#include<iostream>
using namespace std;

int main(){
	
	int num,den;
	
	cout<<"Enter n: "; 
	cin>>num;
	
	cout<<"Enter d: ";
	cin>>den;
	
	try{
		if(num<0)
			throw num;
		else if(den<=0)
			throw den;
		else
			cout<<num/den;
	}
	catch(int exp){
		cout<<"Numerator is'less than 0'";
	}
	catch(...){
		cout<<"Denominator is either '0' or 'less than 0'";
	}
	
	return 0;
}

