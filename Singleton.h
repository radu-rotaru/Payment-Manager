#pragma once

#include "AbstractGestiune.h"
#include "GestiuneCardSpec.h"
#include "Gestiune.h"
#include <vector>

// Clasa arrayOfObjects are rolul de singleton, avem nevoie de un singur vector in care
// sa retinem obiecte in menu.
// Ideea pentru structura clasei: https://www.youtube.com/watch?v=PPup1yeU45I
class ArrayOfObjects {
private:
    vector<AbstractGestiune*> arr;
    ArrayOfObjects() = default;
    ArrayOfObjects(const ArrayOfObjects&) = delete;
    ArrayOfObjects& operator=(const ArrayOfObjects&) = delete;
    ArrayOfObjects& operator=(ArrayOfObjects&&) = delete;
    ~ArrayOfObjects();
    static ArrayOfObjects& Get();
public:
    static void add(AbstractGestiune* x);
    static void printArr();
    static void idPlataClient();
};
