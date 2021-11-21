#include "Cash_Payment.h"

// Constructorul fara parametri
Cash_Payment::Cash_Payment() : sum_of_payment(0), date_of_payment() {
}

// Constructorul cu parametri
Cash_Payment::Cash_Payment(float sum, const Date& date) : sum_of_payment(sum), date_of_payment(date) {
}

// Constructorul de copiere
Cash_Payment::Cash_Payment(const Cash_Payment& p) {
    *this = p;
}

// Supraincarcarea operatorului '=' pentru tipul Cash_Payment
Cash_Payment& Cash_Payment::operator=(const Cash_Payment& p) {
    if (this != &p) {
        sum_of_payment = p.sum_of_payment;
        date_of_payment = p.date_of_payment;
    }
    return *this;
}

// Supraincarcarea operatorului '>>' pentru tipul Cash_Payment
// Ideea pentru acest tip de citire/afisare am gasit-o aici: https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
istream& operator>>(istream& input, Cash_Payment& payment) {
    return payment.read(input);
}

// Supraincarcarea operatorului '<<' pentru tipul Cash_Payment
ostream& operator<<(ostream& output, const Cash_Payment& payment) {
    return payment.write(output);
}

// Functia virtuala pentru citirea unui obiect de tipul Cash_Payment
istream& Cash_Payment::read(istream& input) {
    cout << "Introduceti data platii:\n";
    input >> date_of_payment;
    float x;
    bool ok = true;
    // Verific ca suma introdusa sa nu fie negativa. Daca este,
    // introduc alta valoare.
    while (ok) {
        ok = false;
        cout << "Introduceti suma platita:\n";
        try {
            input >> x;
            if (x <= 0)
                throw x;
        }
        catch (float x) {
            cout << "Suma introdusa nu este valida. Incercati din nou.\n";
            ok = true;
            continue;
        }
    }
    sum_of_payment = x;
    return input;
}

// Functia virtuala pentru afiseara unui obiect de tipul Cash_Payment
ostream& Cash_Payment::write(ostream& output) const {
    output << "Data platii: ";
    output << date_of_payment;
    output << "Suma platita: ";
    output << sum_of_payment << '\n';
    return output;
}
