#include "Product.h"
#include <string>

Product::Product() {}

Product::Product(int id, std::string name, std::string category, double price, int quantity)
    : id(id), name(name), category(category), price(price), quantity(quantity) {}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
std::string Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

void Product::setName(std::string name) {
    this->name = name;
}

void Product::setCategory(std::string category) {
    this->category = category;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Преобразува продукта във формат за запис във файл
std::string Product::toFileString() const {
    return std::to_string(id) + "," +
           name + "," +
           category + "," +
           std::to_string(price) + "," +
           std::to_string(quantity);
}
