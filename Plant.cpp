#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// ===== Абстрактен базов клас =====
class Plant {
protected:
    int id;
    string name;
    string type;
    int fertilizePercent;
    int waterPercent;

public:
    Plant(int id, const string& name, const string& type)
        : id(id), name(name), type(type),
          fertilizePercent(0), waterPercent(0) {}

    virtual ~Plant() {}

    // Pure virtual методи
    virtual void fertilize() = 0;
    virtual void water() = 0;

    virtual void print(ostream& os) const {
        os << "ID: " << id
           << ", Name: " << name
           << ", Type: " << type
           << ", Fertilize: " << fertilizePercent << "%"
           << ", Water: " << waterPercent << "%";
    }

    friend ostream& operator<<(ostream& os, const Plant& p) {
        p.print(os);
        return os;
    }
};

// ===== FloweringPlant =====
class FloweringPlant : public Plant {
    string color;

public:
    FloweringPlant(int id, const string& name, const string& type, const string& color)
        : Plant(id, name, type), color(color) {}

    void fertilize() override {
        if (fertilizePercent + 10 <= 60) {
            fertilizePercent += 10;
            cout << "FloweringPlant fertilized (+10%).\n";
        } else {
            cout << "FloweringPlant cannot be fertilized over 60%.\n";
        }
    }

    void water() override {
        if (waterPercent + 10 <= 50) {
            waterPercent += 10;
            cout << "FloweringPlant watered (+10%).\n";
        } else {
            cout << "FloweringPlant cannot be watered over 50%.\n";
        }
    }

    void print(ostream& os) const override {
        Plant::print(os);
        os << ", Color: " << color;
    }
};

// ===== TreePlant =====
class TreePlant : public Plant {
    double height;

public:
    TreePlant(int id, const string& name, const string& type, double height)
        : Plant(id, name, type), height(height) {}

    void fertilize() override {
        if (fertilizePercent + 10 <= 30) {
            fertilizePercent += 10;
            cout << "TreePlant fertilized (+10%).\n";
        } else {
            cout << "TreePlant cannot be fertilized over 30%.\n";
        }
    }

    void water() override {
        if (waterPercent + 10 <= 80) {
            waterPercent += 10;
            cout << "TreePlant watered (+10%).\n";
        } else {
            cout << "TreePlant cannot be watered over 80%.\n";
        }
    }

    void print(ostream& os) const override {
        Plant::print(os);
        os << ", Height: " << height << " m";
    }
};

// ===== main =====
int main() {
    vector<unique_ptr<Plant>> plants;

    plants.push_back(make_unique<FloweringPlant>(1, "Rose", "Flower", "Red"));
    plants.push_back(make_unique<TreePlant>(2, "Oak", "Tree", 5.5));

    int index;
    char action;

    cout << "Enter plant index (0 or 1): ";
    cin >> index;

    cout << "Enter action (w = water, f = fertilize): ";
    cin >> action;

    if (index >= 0 && index < plants.size()) {
        if (action == 'w') {
            plants[index]->water();
        } else if (action == 'f') {
            plants[index]->fertilize();
        } else {
            cout << "Invalid action.\n";
        }

        cout << *plants[index] << endl;
    } else {
        cout << "Invalid plant index.\n";
    }

    return 0;
}
