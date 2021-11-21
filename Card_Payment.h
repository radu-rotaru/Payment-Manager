#pragma once
#include "Check_Payment.h"
#include "Date.h"
#include <iostream>

using namespace std;

// Clasa pentru tipul de plata prin Card. Retine in plus fata de Check si numarul cardului.
class Card_Payment : public Check_Payment {
private:
    char* card_number;
public:
    Card_Payment();
    Card_Payment(float sum, const Date& date, char* name, char* nr_card);
    Card_Payment(const Card_Payment& p);
    Card_Payment& operator=(const Card_Payment& p);
    ~Card_Payment();
    istream& read(istream& input);
    ostream& write(ostream& output) const;
};

