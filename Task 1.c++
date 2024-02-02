#include <iostream>
#include <string>
#include <limits>

class Car {
public:
    std::string name;
    std::string model;
    int year;

    Car(std::string n, std::string m, int y) : name(n), model(m), year(y) {}

    virtual void displayInfo() const {
        std::cout << year << " " << name << " " << model << std::endl;
    }
};

class ElectricCar : public Car {
public:
    double batteryCapacity;

    ElectricCar(std::string n, std::string m, int y, double bc) : Car(n, m, y), batteryCapacity(bc) {}

    void displayInfo() const override {
        Car::displayInfo();
        std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
    }
};

class GasCar : public Car {
public:
    double fuelEfficiency;

    GasCar(std::string n, std::string m, int y, double fe) : Car(n, m, y), fuelEfficiency(fe) {}

    void displayInfo() const override {
        Car::displayInfo();
        std::cout << "Fuel Efficiency: " << fuelEfficiency << " MPG" << std::endl;
    }
};

int main() {
    std::string carType, name, model;
    int year;

    std::cout << "Enter car type (Electric/Gas): ";
    std::cin >> carType;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline character

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter model: ";
    std::getline(std::cin, model);

    std::cout << "Enter year: ";
    std::cin >> year;

    if (carType == "Electric") {
        double batteryCapacity;
        std::cout << "Enter battery capacity (kWh): ";
        std::cin >> batteryCapacity;

        ElectricCar electricCar(name, model, year, batteryCapacity);
        electricCar.displayInfo();
    } else if (carType == "Gas") {
        double fuelEfficiency;
        std::cout << "Enter fuel efficiency (MPG): ";
        std::cin >> fuelEfficiency;

        GasCar gasCar(name, model, year, fuelEfficiency);
        gasCar.displayInfo();
    } else {
        std::cout << "Invalid car type entered." << std::endl;
    }

    return 0;
}

