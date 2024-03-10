#include "iostream"
using namespace std;

class Engine {
private:
    int cylinders;
    int horsepower;

public:
    // Constructor
    Engine(int cyl = 0, int hp = 0) : cylinders(cyl), horsepower(hp) {}

    // Getter and Setter functions
    void setCylinders(int cyl) {
        cylinders = cyl;
    }

    int getCylinders() const {
        return cylinders;
    }

    void setHorsepower(int hp) {
        horsepower = hp;
    }

    int getHorsepower() const {
        return horsepower;
    }
};

class Car {
private:
    string make;
    string model;
    Engine engine;

public:
    // Constructor
    Car(const string& mk, const string& mdl, int cyl, int pwr) : make(mk), model(mdl), engine(cyl, pwr) {}

    // Getter and Setter functions for Car class
    void setmake(const string& mk) {
        make = mk;
    }

    string getmake() const {
        return make;
    }

    void setModel(const string& mdl) {
        model = mdl;
    }

    string getModel() const {
        return model;
    }

    void setEngine(int cyl, int pwr) {
        engine.setCylinders(cyl);
        engine.setHorsepower(pwr);
    }

    int getEngineCylinders() const {
        return engine.getCylinders();
    }

    int getEngineHorsepower() const {
        return engine.getHorsepower();
    }

    void printInfo() const {
        cout << "The Make of car is: " << make << endl;
        cout << "The Model of the car is: " << model << endl;
        cout << "The number of cylinders in the Engine of the car are: " << engine.getCylinders() << endl;
        cout << "The Horsepower the car engine generates is: " << engine.getHorsepower() << " HP" << endl;
    }
};

int main() {
    string make, model;
    int cylinders, horsepower;
    cout << "Enter the Make of the car: ";
    cin >> make;
    cout << "Enter the Model of the car: ";
    cin >> model;
    cout << "Enter the Cylinders of the car: ";
    cin >> cylinders;
    cout << "Enter the Horsepower of the car: ";
    cin >> horsepower;

    Car c1(make, model, cylinders, horsepower);
    cout << "Car Information: " << endl;
    c1.printInfo();

    return 0;
}
