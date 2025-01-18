#include<iostream>
using namespace std;
int main()
{
	//declare variables
    int num;
    
    //taking input from user
    cout<<"Enter number:";
    cin>>num;
    
    //displaying table
    cout<<"\nMultiplication table of "<<num<<"\n";
    for(int i=1;i<=10;i++)
    {
        cout<<num<<" X "<<i<<" = "<<num*i<<"\n";
    }
    return 0;
}
