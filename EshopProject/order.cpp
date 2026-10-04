#include "Order.h"
#include <iostream>
using namespace std;

Order::Order(int id, vector<Product> items, string name,
             string email, string paymentMethod, double total)
    : id(id), items(items), customerName(name),
      customerEmail(email), paymentMethod(paymentMethod),
      total(total) {}

// Извежда информация за поръчката
void Order::displayOrder() const {
    cout << "Order ID: " << id << endl;
    cout << "Customer: " << customerName << " | Email: " << customerEmail << endl;
    cout << "Payment method: " << paymentMethod << endl;
    cout << "Items:\n";
    for (const auto &p : items) {
        cout << p.getId() << " | " << p.getName() << " | "
             << p.getPrice() << " | " <<"1"<< endl;
    }
    cout << "Total: " << total << endl;
}

