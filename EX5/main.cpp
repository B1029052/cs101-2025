#include <iostream>
#include <string>
using namespace std;

// Super/Base Class
class Car {
protected:
    string m_DriveMode;
public:
    Car(const string& driveMode) : m_DriveMode(driveMode) {}
    string getDriveMode() {
        return m_DriveMode;
    }
};

// Subclass: BMW_Car
class BMW_Car : public Car {
public:
    BMW_Car() : Car("Rear-wheel") {
        cout << "Constructing BMW_Car" << endl;
        cout << "BMW : Drive Mode = " << getDriveMode() << endl;
    }
};

// Subclass: AUDI_Car
class AUDI_Car : public Car {
public:
    AUDI_Car() : Car("Front-wheel") {
        cout << "Constructing AUDI_Car" << endl;
        cout << "Audi : Drive Mode = " << getDriveMode() << endl;
    }
};

// Subclass: BENZ_Car
class BENZ_Car : public Car {
public:
    BENZ_Car() : Car("Front-wheel") {
        cout << "Constructing BENZ_Car" << endl;
        cout << "Benz : Drive Mode = " << getDriveMode() << endl;
    }
};

int main() {
    BMW_Car bmw;
    AUDI_Car audi;
    BENZ_Car benz;
    return 0;
}
