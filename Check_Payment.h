#pragma once

#include "Cash_Payment.h"
#include "Date.h"
#include <iostream>

using namespace std;
// Clasa pentru tipul de plata Check. Retine in plus fata de Cash si numele clientului.
class Check_Payment : public Cash_Payment {
private:
    char* client_name;
public:
    Check_Payment();
    Check_Payment(float sum, const Date& date, char* name);
    Check_Payment(const Check_Payment& p);
    Check_Payment& operator=(const Check_Payment& p);
    ~Check_Payment();
    istream& read(istream& input);
    ostream& write(ostream& output) const;
    char* getName() const;
};

