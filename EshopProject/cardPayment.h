#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H

#include "Payment.h"
#include <iostream>

// Клас CardPayment – конкретна реализация на плащане с карта
class CardPayment : public Payment {
public:
    // Реализация на метода pay
    bool pay(double amount) const override {
        std::cout << "Processing card payment of " << amount << " euro\n";
        std::cout << "Payment successful!\n";
        return true;
    }
};

#endif
