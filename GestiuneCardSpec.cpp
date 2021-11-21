#include "GestiuneCardSpec.h"

// Initializez atributele statice
int Gestiune<Card_Payment>::number_of_clients = 0;
unordered_map<int, unique_ptr<char[]>> Gestiune<Card_Payment>::array_of_clients = {};

// Supraincarcarea operatorului '+=' pentru adaugarea unui client in structura unordered_map
void operator+=(unordered_map<int, unique_ptr<char[]>>& arr, const Gestiune<Card_Payment>& p) {
    unique_ptr<char[]> ptr = make_unique<char[]>(strlen(p.getPaymentInfo().getName()) + 1);
    ptr.reset(p.getPaymentInfo().getName());
    arr.insert({ p.getClientId(), move(ptr) });
}

// Constructorul fara parametri
Gestiune<Card_Payment>::Gestiune() : BaseGestiune<Card_Payment>() {
}

// Constructrul cu parametri
Gestiune<Card_Payment>::Gestiune(int id_p, const Card_Payment& info, int id_c) : BaseGestiune<Card_Payment>(id_p, info) {
    client_id = id_c;
    array_of_clients += *this;
    number_of_clients = array_of_clients.size();
}

// Constructorul de copiere
Gestiune<Card_Payment>::Gestiune(const Gestiune<Card_Payment>& p) : BaseGestiune<Card_Payment>() {
    *this = p;
}

// Functia pentru citirea obiectelor.
istream& Gestiune<Card_Payment>::read(istream& input) {
    BaseGestiune<Card_Payment>::read(input);
    int x;
    bool ok = true;
    // Verific daca mai exista deja un client cu id-ul respectiv.
    // Daca exista, introduc alt id pana cand este citit unul valid.
    while (ok) {
        ok = false;
        cout << "Introduceti id clientului:\n";
        try {
            input >> x;
            if (array_of_clients.find(x) != array_of_clients.end())
                throw true;
        }
        catch (bool) {
            cout << "Exista deja un client cu acest id. Incercati din nou.\n";
            ok = true;
            continue;
        }
    }
    client_id = x;
    array_of_clients += *this;
    number_of_clients = array_of_clients.size();
    return input;
}

// Functia pentru afisarea obiectelor
ostream& Gestiune<Card_Payment>::write(ostream& output) const {
    BaseGestiune<Card_Payment>::write(output);
    output << "Id client: ";
    output << client_id << '\n';
    return output;
}

// Supraincarcarea operatorului '='
Gestiune<Card_Payment>& Gestiune<Card_Payment>::operator=(const Gestiune<Card_Payment>& p) {
    BaseGestiune::operator=(p);
    client_id = p.client_id;
    return *this;
}

// Getter pentru id-ul clientului
int Gestiune<Card_Payment>::getClientId() const {
    return client_id;
}

// Getter pentru numarul de clienti
int Gestiune<Card_Payment>::getNumberOfClients() {
    return number_of_clients;
}

// Functia pentru afisarea structurii unordered_map
void Gestiune<Card_Payment>::printArrayOfClients() {
    int i = 1;
    for (auto& it : array_of_clients) {
        cout << "Clientul nr. " << i++ << '\n';
        cout << it.second.get() << '\n';
    }
}