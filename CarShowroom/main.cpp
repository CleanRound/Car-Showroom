#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

struct Car {
    string name;
    int year;
    double engineVolume;
    double price;

    Car(string name, int year, double engineVolume, double price)
        : name(name), year(year), engineVolume(engineVolume), price(price) {}
};

struct SortByName {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.name < car2.name;
    }
};

struct SortByYear {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.year < car2.year;
    }
};

struct SortByPrice {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.price < car2.price;
    }
};

void displayCar(const Car& car) {
    cout << "Name: " << car.name << ", Year: " << car.year << ", Engine Volume: " << car.engineVolume << ", Price: " << car.price << endl;
}

void addCar(vector<Car>& inventory) {
    string name;
    int year;
    double engineVolume, price;

    cout << "Enter Car Details:" << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Year: ";
    cin >> year;
    cout << "Engine Volume: ";
    cin >> engineVolume;
    cout << "Price: ";
    cin >> price;

    inventory.push_back(Car(name, year, engineVolume, price));
}

void deleteCar(vector<Car>& inventory, const string& name) {
    auto it = find_if(inventory.begin(), inventory.end(), [&name](const Car& car) {
        return car.name == name;
        });

    if (it != inventory.end()) {
        inventory.erase(it);
        cout << "Car '" << name << "' deleted successfully." << endl;
    }
    else {
        cout << "Car '" << name << "' not found." << endl;
    }
}

void searchCarByName(const vector<Car>& inventory, const string& name) {
    vector<Car> result;
    copy_if(inventory.begin(), inventory.end(), back_inserter(result), [&name](const Car& car) {
        return car.name == name;
        });

    if (!result.empty()) {
        for (const auto& car : result) {
            displayCar(car);
        }
    }
    else {
        cout << "Car with name '" << name << "' not found." << endl;
    }
}

void searchCarByYear(const vector<Car>& inventory, int year) {
    vector<Car> result;
    copy_if(inventory.begin(), inventory.end(), back_inserter(result), [&year](const Car& car) {
        return car.year == year;
        });

    if (!result.empty()) {
        for (const auto& car : result) {
            displayCar(car);
        }
    }
    else {
        cout << "Car with year '" << year << "' not found." << endl;
    }
}

void searchCarByEngineVolume(const vector<Car>& inventory, double engineVolume) {
    vector<Car> result;
    copy_if(inventory.begin(), inventory.end(), back_inserter(result), [&engineVolume](const Car& car) {
        return car.engineVolume == engineVolume;
        });

    if (!result.empty()) {
        for (const auto& car : result) {
            displayCar(car);
        }
    }
    else {
        cout << "Car with engine volume '" << engineVolume << "' not found." << endl;
    }
}

void searchCarByPrice(const vector<Car>& inventory, double price) {
    vector<Car> result;
    copy_if(inventory.begin(), inventory.end(), back_inserter(result), [&price](const Car& car) {
        return car.price == price;
        });

    if (!result.empty()) {
        for (const auto& car : result) {
            displayCar(car);
        }
    }
    else {
        cout << "Car with price '" << price << "' not found." << endl;
    }
}

void sortInventoryByName(vector<Car>& inventory) {
    sort(inventory.begin(), inventory.end(), SortByName());
}

void sortInventoryByYear(vector<Car>& inventory) {
    sort(inventory.begin(), inventory.end(), SortByYear());
}

void sortInventoryByPrice(vector<Car>& inventory) {
    sort(inventory.begin(), inventory.end(), SortByPrice());
}

int main() {
    vector<Car> inventory;

    inventory.push_back(Car("Toyota Camry", 2020, 2.5, 25000));
    inventory.push_back(Car("Honda Accord", 2019, 2.0, 22000));
    inventory.push_back(Car("Ford Mustang", 2021, 5.0, 40000));

    cout << "All Cars:" << endl;
    for (const auto& car : inventory) {
        displayCar(car);
    }
    cout << endl;

    addCar(inventory);

    sortInventoryByName(inventory);

    cout << "Cars after adding and sorting by name:" << endl;
    for (const auto& car : inventory) {
        displayCar(car);
    }
    cout << endl;

    sortInventoryByYear(inventory);

    cout << "Cars after sorting by year:" << endl;
    for (const auto& car : inventory) {
        displayCar(car);
    }
    cout << endl;

    sortInventoryByPrice(inventory);

    cout << "Cars after sorting by price:" << endl;
    for (const auto& car : inventory) {
        displayCar(car);
    }
    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string searchName;
    cout << "Enter the name of the car you want to search: ";
    getline(cin, searchName);
    cout << "Searching for a car by name:" << endl;
    searchCarByName(inventory, searchName);
    cout << endl;

    int searchYear;
    cout << "Enter the year of the car you want to search: ";
    cin >> searchYear;
    cout << "Searching for a car by year:" << endl;
    searchCarByYear(inventory, searchYear);
    cout << endl;

    double searchEngineVolume;
    cout << "Enter the engine volume of the car you want to search: ";
    cin >> searchEngineVolume;
    cout << "Searching for a car by engine volume:" << endl;
    searchCarByEngineVolume(inventory, searchEngineVolume);
    cout << endl;

    double searchPrice;
    cout << "Enter the price of the car you want to search: ";
    cin >> searchPrice;
    cout << "Searching for a car by price:" << endl;
    searchCarByPrice(inventory, searchPrice);
    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string deleteName;
    cout << "Enter the name of the car you want to delete: ";
    getline(cin, deleteName);
    deleteCar(inventory, deleteName);
    cout << endl;

    cout << "Cars after deletion:" << endl;
    for (const auto& car : inventory) {
        displayCar(car);
    }
    cout << endl;

    return 0;
}
