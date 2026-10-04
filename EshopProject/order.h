#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Product.h"
using namespace std;

class Order {
private:
    int id;     // Уникален идентификатор на поръчката
    vector<Product> items;  // Продукти в поръчката
    double total;         // Обща стойност на поръчката
    string customerName;    // Име на клиента  
    string customerEmail;   // Имейл на клиента
    string paymentMethod;   // Метод на плащане

public:
    Order(int id, vector<Product> items, string name, string email, string paymentMethod, double total);        
    void displayOrder() const;      // Извежда информация за поръчката
    string getCustomerEmail() const { return customerEmail;}
};

#endif
