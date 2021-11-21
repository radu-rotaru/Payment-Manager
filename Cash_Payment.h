#pragma once
#include "Date.h"
#include <iostream>

using namespace std;

// Clasa pentru tipul de plata Cash. Pentru acest tip de plata se retin doar data si suma platita.
class Cash_Payment {
private:
    Date date_of_payment;
    float sum_of_payment;
public:
    Cash_Payment();
    Cash_Payment(float sum, const Date& date);
    Cash_Payment(const Cash_Payment& p);
    virtual ~Cash_Payment() = default;
    Cash_Payment& operator=(const Cash_Payment& p);
    friend istream& operator>>(istream& input, Cash_Payment& payment);
    friend ostream& operator<<(ostream& output, const Cash_Payment& payment);
    virtual istream& read(istream& input);
    virtual ostream& write(ostream& output) const;
};

