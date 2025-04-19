#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class
class Vehicle {
protected:
    string vehicleID, make, model;
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(string id, string mk, string mdl, int yr, double rate)
        : vehicleID(id), make(mk), model(mdl), year(yr), dailyRentalRate(rate), isRented(false) {}

    string getVehicleID() const { return vehicleID; }
    bool getIsRented() const { return isRented; }

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }

    virtual double calculateRentalCost(int days) = 0;
    virtual void displayDetails() {
        cout << "Vehicle ID   : " << vehicleID << endl;
        cout << "Make         : " << make << endl;
        cout << "Model        : " << model << endl;
        cout << "Year         : " << year << endl;
        cout << "Daily Rate   : $" << dailyRentalRate << endl;
        cout << "Rented       : " << (isRented ? "Yes" : "No") << endl;
    }

    virtual ~Vehicle() {}
};

// Car Class
class Car : public Vehicle {
    int numberOfDoors;
    string fuelType;
public:
    Car(string id, string mk, string mdl, int yr, double rate, int doors, string fuel)
        : Vehicle(id, mk, mdl, yr, rate), numberOfDoors(doors), fuelType(fuel) {}

    double calculateRentalCost(int days) {
        return dailyRentalRate * days;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Doors        : " << numberOfDoors << endl;
        cout << "Fuel Type    : " << fuelType << endl;
        cout << "-----------------------------\n";
    }
};

// Motorcycle Class
class Motorcycle : public Vehicle {
    string engineType;
    bool hasSidecar;
public:
    Motorcycle(string id, string mk, string mdl, int yr, double rate, string engine, bool sidecar)
        : Vehicle(id, mk, mdl, yr, rate), engineType(engine), hasSidecar(sidecar) {}

    double calculateRentalCost(int days) {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Engine Type  : " << engineType << endl;
        cout << "Sidecar      : " << (hasSidecar ? "Yes" : "No") << endl;
        cout << "-----------------------------\n";
    }
};

// Truck Class
class Truck : public Vehicle {
    double cargoCapacity;
    int numberOfAxles;
public:
    Truck(string id, string mk, string mdl, int yr, double rate, double capacity, int axles)
        : Vehicle(id, mk, mdl, yr, rate), cargoCapacity(capacity), numberOfAxles(axles) {}

    double calculateRentalCost(int days) {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Cargo Cap.   : " << cargoCapacity << " m^3" << endl;
        cout << "Axles        : " << numberOfAxles << endl;
        cout << "-----------------------------\n";
    }
};

// Rental System
class RentalSystem {
    vector<Vehicle*> vehicles;
public:
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() {
        cout << "\nAvailable Vehicles:\n";
        for (int i = 0; i < vehicles.size(); i++) {
            if (!vehicles[i]->getIsRented()) {
                vehicles[i]->displayDetails();
            }
        }
    }

    Vehicle* findVehicle(string id) {
        for (int i = 0; i < vehicles.size(); i++) {
            if (vehicles[i]->getVehicleID() == id)
                return vehicles[i];
        }
        return NULL;
    }

    void rentVehicle(string id, int days) {
        Vehicle* v = findVehicle(id);
        if (v != NULL && !v->getIsRented()) {
            double cost = v->calculateRentalCost(days);
            v->rentVehicle();
            cout << "Rental successful. Total cost: $" << cost << endl;
        } else {
            cout << "Vehicle not available or already rented.\n";
        }
    }

    void returnVehicle(string id) {
        Vehicle* v = findVehicle(id);
        if (v != NULL && v->getIsRented()) {
            v->returnVehicle();
            cout << "Vehicle returned successfully.\n";
        } else {
            cout << "Invalid vehicle ID or vehicle not rented.\n";
        }
    }

    ~RentalSystem() {
        for (int i = 0; i < vehicles.size(); i++) {
            delete vehicles[i];
        }
    }
};

// Main Menu
int main() {
    RentalSystem system;

    system.addVehicle(new Car("CAR123", "Toyota", "Corolla", 2020, 50, 4, "Petrol"));
    system.addVehicle(new Motorcycle("MOTO456", "Yamaha", "R15", 2022, 30, "Inline-4", false));
    system.addVehicle(new Truck("TRUCK789", "Tata", "HeavyDuty", 2018, 80, 15.0, 4));

    int choice;
    do {
        cout << "\n1. Display Available Vehicles\n2. Rent a Vehicle\n3. Return a Vehicle\n4. Find Vehicle and Display Details\n5. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system.displayAvailableVehicles();
        } else if (choice == 2) {
            string id;
            int days;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter number of days: ";
            cin >> days;
            system.rentVehicle(id, days);
        } else if (choice == 3) {
            string id;
            cout << "Enter Vehicle ID to return: ";
            cin >> id;
            system.returnVehicle(id);
        } else if (choice == 4) {
            string id;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            Vehicle* v = system.findVehicle(id);
            if (v != NULL)
                v->displayDetails();
            else
                cout << "Vehicle not found.\n";
        }
    } while (choice != 5);

    return 0;
}

