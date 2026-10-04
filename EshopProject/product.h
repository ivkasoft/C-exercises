#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

// Клас Product – описва един продукт в електронния магазин
class Product {
private:
    int id;         // Уникален идентификатор на продукта
    string name;    // Име на продукта
    string category;// Категория (Mouse, Laptop, Monitor)
    double price;   // Цена на продукта
    int quantity;   // Налично количество

public:
    // Конструктори
    Product();
    Product(int id, string name, string category, double price, int quantity);

    // Getter методи
    int getId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getQuantity() const;

    // Setter методи
    void setName(string name);
    void setCategory(string category);
    void setPrice(double price);
    void setQuantity(int quantity);

    // Преобразува продукта във формат за запис във файл
    string toFileString() const; 
};

#endif
