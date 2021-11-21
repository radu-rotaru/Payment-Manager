#pragma once

#include "BaseGestiune.h"
#include "Card_Payment.h"
#include "Gestiune.h"

// Clasa specializata pentru tipul Card_Payment. Mosteneste clasa baseGestiune<Card_Payment> si mai
// adauga numarul de clienti, structura pentru retinerea numelor acestora si id-ul clientului. Folosesc tot un unordered_map
// pentru stocarea numelor clientilor, id-ul clientilor reprezentand cheia.
template <>
class Gestiune<Card_Payment> : public BaseGestiune<Card_Payment> {
private:
    static int number_of_clients;
    static unordered_map<int, unique_ptr<char[]>> array_of_clients;
    int client_id;
public:
    Gestiune();
    Gestiune(int id_p, const Card_Payment& info, int id_c);
    Gestiune(const Gestiune& p);
    ~Gestiune() = default;
    friend void operator+=(unordered_map<int, unique_ptr<char[]>>& arr, const Gestiune<Card_Payment>& p);
    istream& read(istream& input);
    ostream& write(ostream& output) const;
    Gestiune<Card_Payment>& operator=(const Gestiune<Card_Payment>&);
    int getClientId() const;
    static int getNumberOfClients();
    static void printArrayOfClients();
};
