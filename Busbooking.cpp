//Bus Booking
#include<iostream>
using namespace std;

static int no_of_seats = 40;

class Booking{
	private:
		int booked_seats;
		int remaining_seats;
		
	public:
		Booking(int booked_seats){
		remaining_seats = no_of_seats;
			
			try{
				if(remaining_seats<booked_seats)
					throw remaining_seats;
				else{
					
					remaining_seats = no_of_seats - booked_seats;
					no_of_seats = remaining_seats;
					cout<<endl<<"remaining seats: "<<remaining_seats;
					cout<<endl<<"Ticket Booked";
				}
			}
			catch(int exp){
				cout<<"No space";
			}
		}
};

int main(){
	Booking b1(40);
	Booking b2(20);
}
