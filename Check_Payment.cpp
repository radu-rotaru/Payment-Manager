#include "Check_Payment.h"

// Constructorul fara parametri
Check_Payment::Check_Payment() : Cash_Payment(), client_name(NULL) {
}

// Constructorul cu parametri
Check_Payment::Check_Payment(float sum, const Date& date, char* name)
    : Cash_Payment(sum, date) {
    client_name = new char[strlen(name) + 1];
    strcpy_s(client_name, strlen(name) + 1, name);
}

// Constructorul de copiere
Check_Payment::Check_Payment(const Check_Payment& p) : Check_Payment() {
    *this = p;
}

// Destructorul
Check_Payment::~Check_Payment() {
    if (client_name != NULL)
        delete[] client_name;
}

// Supraincarcarea operatorului '=' pentru tipul Check.
// Apeleaza si operatorul '=' pentru tipul Cash
Check_Payment& Check_Payment::operator=(const Check_Payment& p) {
    if (this != &p) {
        Cash_Payment::operator=(p);
        if (client_name != NULL)
            delete[] client_name;
        client_name = new char[strlen(p.client_name) + 1];
        strcpy_s(client_name, strlen(p.client_name) + 1, p.client_name);
    }
    return *this;
}

// Functia virtuala pentru citirea obiectelor.
// Apeleaza functia din Cash_Payment pentru a citi intai
// partea din Cash_Payment, dupa care citeste si atributele specifice
// tipului Check_Payment.
istream& Check_Payment::read(istream& input) {
    Cash_Payment::read(input);
    char x[100];
    bool ok = true;
    // Am incercat sa fac in asa fel incat numele introdus sa fie cat mai corect.
    // Numele ar trebui sa contina doar litere si sa fie de forma INITCAP
    // (prima litera din fiecare nume ar trebui sa fie majuscula, iar restul minuscule).
    while (ok) {
        ok = false;
        try {
            cout << "Introduceti nume client:\n";
            input.ignore();
            input.get(x, 100);
            bool upLow = false;
            for (int i = 0; i < strlen(x); ++i) {
                if (x[i] == ' ') {
                    upLow = false;
                    continue;
                }
                if (upLow == false) {
                    if (!isupper(x[i]))
                        throw false;
                    upLow = true;
                }
                else {
                    if (!islower(x[i]))
                        throw false;
                }
            }
        }
        catch (bool) {
            cout << "Numele introdus nu este un nume valid. Incercati din nou.\n";
            ok = true;
            continue;
        }
    }
    if (client_name != NULL)
        delete[] client_name;
    client_name = new char[strlen(x) + 1];
    strcpy_s(client_name, strlen(x) + 1, x);
    return input;
}

// Functia virtuala pentru afisarea obiectelor.
// Apeleaza functia din Cash_Payment pentru a afisa intai
// partea din Cash_Payment, dupa care afiseaza si atributele specifice
// tipului Check_Payment.
ostream& Check_Payment::write(ostream& output) const {
    Cash_Payment::write(output);
    output << "Nume client: ";
    output << client_name << '\n';
    return output;
}

// Getter pentru nume
char* Check_Payment::getName() const {
    return client_name;
}
