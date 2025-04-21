//area of rectangle and circle
#include<iostream>
using namespace std;
class Area{
	
	private:
		float l, b, r;
		const float PI = 3.14;
	
	public:
		Area(float r){
			cout<<"Area of Circle: "<<PI*r*r<<endl;
		}
		
		Area(float l, float b){
			cout<<"Area of Rectangle: "<<l*b<<endl;
		}
};

int main(){
	
	Area c(3.0);
	Area r(10.0,13.0);
	return 0;
}
