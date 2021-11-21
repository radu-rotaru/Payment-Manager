#pragma once
#include "AbstractGestiune.h"
#include <unordered_map>

using namespace std;
// Template-ul BaseGestiune. Am facut acest template pentru a evita duplicarea codului in specializarea pentru tipul Card.
// Am considerat ca o chitanta este adaugata doar in momentul in care citesc un obiect de la tastatura sau este apelat constructorul cu parametri.
// Pentru cel fara parametri, nu ar fi avut prea mult sens sa adaug o chitanta goala, iar pentru cel de copiere, inseamna ca deja a fost adaugata o chitanta
// cu aceleasi date. Am pus constructorii 'protected' pentru a nu putea crea obiecte de acest tip din afara.
template <class T>
class BaseGestiune : public AbstractGestiune {
private:
    static int number_of_payments;
    static unordered_map<int, T> array_of_payments;
    int payment_id;
    T payment_info;
    void makeConcrete() {};
protected:
    BaseGestiune();
    BaseGestiune(int id, T info);
    BaseGestiune(const BaseGestiune& p);
public:
    ~BaseGestiune() = default;
    istream& read(istream& input);
    ostream& write(ostream& output) const;
    BaseGestiune& operator=(const BaseGestiune& p);
    template <class T1, class T2> friend void operator+=(unordered_map<int, T1>& arr, const BaseGestiune<T2>& p);
    const T& getPaymentInfo() const;
    int getIdPlata() const;
    static int getNumberOfPayments();
    static void printArrayOfPayments();
};

// Initializez atributele statice
template <class T> int BaseGestiune<T>::number_of_payments = 0;

template <class T> unordered_map<int, T> BaseGestiune<T>::array_of_payments = {};

// Getter pentru datele platii
template <class T>
const T& BaseGestiune<T>::getPaymentInfo() const {
    return payment_info;
}

// Supraincarcarea operatorului '+=' pentru adaugarea datelor unei plati in structura unordered_map
template <class T1, class T2>
void operator+=(unordered_map<int, T1>& arr, const BaseGestiune<T2>& p) {
    arr.insert({ p.payment_id, p.payment_info });
}

// Constructorul fara parametri
template <class T>
BaseGestiune<T>::BaseGestiune() : payment_id(0), payment_info() {
}

// Constructorul cu parametri, adaug datele platii si actualizez numarul de plati
template <class T>
BaseGestiune<T>::BaseGestiune(int id, T info) : payment_id(id), payment_info(info) {
    array_of_payments += *this;
    number_of_payments = array_of_payments.size();
}

// Constructorul de copiere
template <class T>
BaseGestiune<T>::BaseGestiune(const BaseGestiune<T>& p) : BaseGestiune() {
    *this = p;
}

//Getter pentru id-ul platii
template <class T>
int BaseGestiune<T>::getIdPlata() const {
    return payment_id;
}

// Functia folosita pentru citirea unui obiect.
template <class T>
istream& BaseGestiune<T>::read(istream& input) {
    int x;
    bool ok = true;
    // Verific daca mai exista deja o plata cu id-ul respectiv.
    // Daca exista, introduc alt id pana cand este citit unul valid.
    while (ok) {
        ok = false;
        cout << "Introduceti id plata:\n";
        try {
            input >> x;
            if (array_of_payments.count(x))
                throw false;
        }
        catch (bool) {
            cout << "Exista deja o plata cu acest id. Incercati din nou.\n";
            ok = true;
            continue;
        }
    }
    // Citesc si detaliile platii, dupa care adaug obiectul in unordered_map si actualizez numarul de plati
    payment_id = x;
    cout << "Introduceti detalii plata:\n";
    input >> payment_info;
    array_of_payments += *this;
    number_of_payments = array_of_payments.size();
    return input;
}

// Functia pentru afisarea obiectelor.
template <class T>
ostream& BaseGestiune<T>::write(ostream& output) const {
    output << "Id plata: ";
    output << payment_id << '\n';
    output << "Detalii plata:\n";
    output << payment_info;
    return output;
}

// Supraincarcarea operatorului '='
template <class T>
BaseGestiune<T>& BaseGestiune<T>::operator=(const BaseGestiune<T>& p) {
    if (this != &p) {
        payment_id = p.payment_id;
        payment_info = p.payment_info;
    }
    return *this;
}

// Getter pentru numarul de plati.
template <class T>
int BaseGestiune<T>::getNumberOfPayments() {
    return number_of_payments;
}

// Functie pentru afisarea detaliilor platilor introduse
template <class T>
void BaseGestiune<T>::printArrayOfPayments() {
    int i = 1;
    for (auto& it : array_of_payments) {
        cout << "Plata nr. " << i++ << '\n';
        cout << it.second;
    }
}
