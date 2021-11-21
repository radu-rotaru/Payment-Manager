#pragma once

#include "BaseGestiune.h"

// Template-ul Gestiune. Gestionarea platilor inseamna retinerea datelor despre o anumita plata 
// si atribuirea unui id acesteia. Clasele formate mostenesc clasa de acelasi tip
// formata de baseGestiune. Structura este la fel ca cea din baseGestiune, constructorii nu sunt
// mosteniti si trebuie definiti.
template <class T>
class Gestiune : public BaseGestiune<T> {
public:
    Gestiune();
    Gestiune(int id, T info);
    Gestiune(const Gestiune& p);
    ~Gestiune() = default;
};

// Constructorul fara parametri
template <class T>
Gestiune<T>::Gestiune() : BaseGestiune<T>() {
};

// Constructorul cu parametri
template <class T>
Gestiune<T>::Gestiune(int id, T info) : BaseGestiune<T>(id, info) {
};

// Constructorul de copiere
template <class T>
Gestiune<T>::Gestiune(const Gestiune<T>& p) : BaseGestiune<T>(p) {
};