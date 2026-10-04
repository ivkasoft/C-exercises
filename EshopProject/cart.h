#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"
using namespace std;

// Клас Cart – описва количката за пазаруване
class Cart {
private:
    vector<Product> items; //   Продукти в количката

public:
    void addToCart(const Product &p);   
    void removeFromCart(int productId); 
    void listCart() const;               
    double calculateTotal() const;      
    bool isEmpty() const;          
    vector<Product> getItems() const;   
    void clear();                   
};

#endif
