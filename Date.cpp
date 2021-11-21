#include "Date.h"

// Constructorul fara parametri, initializeaza atributele cu 0
Date::Date() : day(0), month(0), year(0) {
}

// Constructorul cu parametri
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
}

// Constructorul de copiere, apeleaza supraincarcarea operatorului '='
Date::Date(const Date& date) {
    *this = date;
}

// Supraincarcarea operatorului '>>' pentru tipul Date
istream& operator>>(istream& input, Date& date) {
    bool ok = true;
    int x, y, z;
    // Verific in while daca ziua, luna si anul introduse sunt valide.
    // In cazul in care nu sunt, introduc alte valori.
    while (ok) {
        ok = false;
        cout << "Introduceti ziua:\n";
        try {
            input >> x;
            if (x > 31 || x < 1)
                throw x;
        }
        catch (int x) {
            cout << "Ziua introdusa este incorecta\n";
            ok = true;
            continue;
        }
        cout << "Introduceti luna(numar):\n";
        try {
            input >> y;
            if (y > 12 || y < 1)
                throw y;
        }
        catch (int y) {
            cout << "Luna introdusa este incorecta\n";
            ok = true;
            continue;
        }
        try {
            if (x > Date::days_of_month[y - 1])
                throw x;
        }
        catch (int x) {
            cout << "Aceasta luna are doar " << Date::days_of_month[y - 1] << " de zile.\n";
            ok = true;
            continue;
        }

        cout << "Introduceti anul:\n";
        try {
            input >> z;
            if (x == 29 && y == 2 && (z % 4 || (z % 4 == 0 && z % 100 == 0 && z % 400)))
                throw z;
        }
        catch (int z) {
            cout << "Anul nu este bisect.\n";
            ok = true;
            continue;
        }
    }
    date.day = x;
    date.month = y;
    date.year = z;
    return input;
}

// Supraincarcarea operatorului '<<' pentru tipul Date
ostream& operator<<(ostream& output, const Date& date) {
    output << date.day << "/" << date.month << "/" << date.year << '\n';
    return output;
}

// Supraincarcarea operatorului '=' pentru tipul Date
Date& Date::operator=(const Date& date) {
    if (this != &date) {
        day = date.day;
        month = date.month;
        year = date.year;
    }
    return *this;
}

// Getter pentru zi
int Date::get_day() const {
    return day;
}

// Getter pentru luna
int Date::get_month() const {
    return month;
}

// Getter pentru an
int Date::get_year() const {
    return year;
}
