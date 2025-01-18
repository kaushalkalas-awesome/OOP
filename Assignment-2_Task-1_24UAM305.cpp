#include <iostream>
using namespace std;
int main()
{
	//initialize variables
    int num1,num2;
    
    //taking input from user
    cout<<"Enter num1:";
    cin>>num1;
    cout<<"Enter num2";
    cin>>num2;
    
    //performing Addition
    cout<<"Addition of "<<num1<<"+"<<num2<<"="<<num1+num2<<"\n";
    
    //performing Substraction
    cout<<"Substraction of "<<num1<<"-"<<num2<<"="<<num1-num2<<"\n";
    
    //performing Multiplication
    cout<<"Multiplication of "<<num1<<"*"<<num2<<"="<<num1*num2<<"\n";
    
    //performing Division
    cout<<"Division of "<<num1<<"/"<<num2<<"="<<num1/num2;
    
    return 0;
}
