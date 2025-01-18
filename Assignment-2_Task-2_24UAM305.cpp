#include<iostream>
using namespace std;
int main()
{
	//declaring variables
    int num1,num2,num3;
    
    //taking input from user
    cout<<"Enter num1:";
    cin>>num1;
    cout<<"Enter num2:";
    cin>>num2;
    cout<<"Enter num3";
    cin>>num3;

	if(num1>num2 && num1>num3){
		cout<<"Largest is: "<<num1;
	}
	else if(num2>num1 && num2>num3){
		cout<<"Largest is num2: "<<num2;
	}
	else{
		cout<<"Largest is num3: "<<num3;
	}

    return 0;
}
