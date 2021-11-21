#include "Factory.h"

AbstractGestiune* FactoryOfPayments::createObject(int type) {
    switch (type) {
    case 1:
        return new Gestiune<Cash_Payment>;
    case 2:
        return new Gestiune<Check_Payment>;
    case 3:
        return new Gestiune<Card_Payment>;
    default:
        int x;
        cout << "Valoarea introdusa este invalida. Introduceti un tip valid:.\n";
        cin >> x;
        return createObject(x);
    }
}
