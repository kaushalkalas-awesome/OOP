//Exception handling
#include<iostream>
using namespace std;

class ZeroDivision{
};

class NegativeNumber{
};

int main(){
	
	int num,den;
	
	cout<<"Enter n: "; 
	cin>>num;
	
	cout<<"Enter d: ";
	cin>>den;
	
	try{
		if(num<0)
			throw NegativeNumber();
		else if(den<=0)
			throw ZeroDivision();
		else
			cout<<num/den;
	}
	catch(NegativeNumber n){
		cout<<"Numerator is'less than 0'";
	}
	catch(...){
		cout<<"Denominator is either '0' or 'less than 0'";
	}
	
	return 0;
}

