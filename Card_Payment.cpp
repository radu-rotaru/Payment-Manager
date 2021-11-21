#include "Card_Payment.h"

// Constructorul fara parametri
Card_Payment::Card_Payment() : Check_Payment(), card_number(NULL) {
}

// Constructorul cu parametri
Card_Payment::Card_Payment(float sum, const Date& date, char* name, char* nr_card)
    : Check_Payment(sum, date, name) {
    card_number = new char[strlen(nr_card) + 1];
    strcpy_s(card_number, strlen(nr_card) + 1, nr_card);
}

// Constructorul de copiere
Card_Payment::Card_Payment(const Card_Payment& p) : Card_Payment() {
    *this = p;
}

// Destructorul
Card_Payment::~Card_Payment() {
    if (card_number != NULL)
        delete[] card_number;
}

// Supraincarcarea operatorului '=' pentru tipul Card.
// Apeleaza si operatorul '=' pentru tipul Check
Card_Payment& Card_Payment::operator=(const Card_Payment& p) {
    if (this != &p) {
        Check_Payment::operator=(p);
        if (card_number != NULL)
            delete[] card_number;
        card_number = new char[strlen(p.card_number) + 1];
        strcpy_s(card_number, strlen(p.card_number) + 1, p.card_number);
    }
    return *this;
}

// Functia virtuala pentru citirea obiectelor.
// Apeleaza functia din Check_Payment pentru a citi intai
// partea din Check_Payment, dupa care citeste si atributele specifice
// tipului Card_Payment.
istream& Card_Payment::read(istream& input) {
    Check_Payment::read(input);
    char x[100];
    bool ok = true;
    // Am incercat sa fac in asa fel incat numarul cardului introdus sa fie cat mai corect.
    // Numarul cardului ar trebui sa contina doar cifre si sa aiba o lungime de 16 caractere.
    while (ok) {
        ok = false;
        cout << "Introduceti numar card:\n";
        try {
            input >> x;
            if (strlen(x) != 16)
                throw true;

            for (int i = 0; i < strlen(x); ++i) {
                if (!isdigit(x[i]))
                    throw false;
            }
        }
        catch (bool exc) {
            if (exc == true)
                cout << "Numarul cardului trebuie sa aiba 16 cifre.\n";
            else
                cout << "Numarul cardului trebuie sa fie format doar din cifre.\n";
            ok = true;
            continue;
        }
    }
    if (card_number != NULL)
        delete[] card_number;
    card_number = new char[strlen(x) + 1];
    strcpy_s(card_number, strlen(x) + 1, x);

    return input;
}

// Functia virtuala pentru afisarea obiectelor.
// Apeleaza functia din Check_Payment pentru a afisa intai
// partea din Check_Payment, dupa care afiseaza si atributele specifice
// tipului Card_Payment.
ostream& Card_Payment::write(ostream& output) const {
    Check_Payment::write(output);
    output << "Numar card: ";
    output << card_number << '\n';
    return output;
}
