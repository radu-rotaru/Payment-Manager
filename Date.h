#pragma once
#include <iostream>

using namespace std;

// Clasa Date, reprezinta o data calendaristica
class Date {
private:
    int day;
    int month;
    int year;
    // days_of_month retine pentru fiecare luna numarul maxim de zile
    static constexpr int days_of_month[12]{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& date);
    ~Date() = default;
    friend istream& operator>>(istream& input, Date& date);
    friend ostream& operator<<(ostream& output, const Date& date);
    Date& operator=(const Date& date);
    int get_day() const;
    int get_month() const;
    int get_year() const;
};

