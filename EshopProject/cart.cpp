#include "Cart.h"
#include <iostream>
using namespace std;

// Добавя продукт в количката
void Cart::addToCart(const Product &p) {
    items.push_back(p);
    cout << "Product added to cart!\n";
}

// Премахва продукт в количката
void Cart::removeFromCart(int productId) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getId() == productId) {
            items.erase(items.begin() + i);
            cout << "Product removed from cart.\n";
            return;
        }
    }
    cout << "Product not found in cart.\n";
}

// Изброява продуктите в количката
void Cart::listCart() const {
    if (items.empty()) {
        cout << "Cart is empty.\n";
        return;
    }
    for (const auto &p : items) {
        cout << p.getId() << " | " << p.getName() << " | "
             << p.getPrice() << " | " << p.getQuantity() << endl;
    }
}

// Изчислява общата стойност на продуктите в количката
double Cart::calculateTotal() const {
    double total = 0;
    for (const auto &p : items) total += p.getPrice();
    return total;
}

// Проверява дали количката е празна
bool Cart::isEmpty() const {
    return items.empty();
}

// Връща продуктите в количката
vector<Product> Cart::getItems() const {
    return items;
}

// Изчиства количката
void Cart::clear() {
    items.clear();
}
