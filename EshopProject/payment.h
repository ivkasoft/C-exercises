#ifndef PAYMENT_H
#define PAYMENT_H

// Абстрактен клас Payment – описва интерфейс за плащане
class Payment {
public:
    virtual bool pay(double amount) const = 0; // абстрактен метод
    virtual ~Payment() {}
};

#endif