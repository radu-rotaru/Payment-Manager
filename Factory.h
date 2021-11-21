#pragma once

#include "AbstractGestiune.h"
#include "GestiuneCardSpec.h"
#include "Gestiune.h"

// Clasa FactoryOfPayments, este o clasa factory, are implementata doar o metoda publica.
// Ideea pentru structura clasei: https://sourcemaking.com/design_patterns/factory_method/cpp/1
class FactoryOfPayments {
public:
    AbstractGestiune* createObject(int type);
};
