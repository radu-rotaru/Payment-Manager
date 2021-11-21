#pragma once
#include <iostream>

using namespace std;

// Am implementat clasa AbstractGestiune in ideea de a avea o 'interfata'.
// Aveam nevoie de o clasa de baza pentru a crea un vector care sa contina
// obiecte de orice tip. Am facut o functie makeConcrete care are doar scopul
// de a face AbstractGestiune o clasa abstracta.
class AbstractGestiune {
private:
    virtual void makeConcrete() = 0;

public:
    virtual ~AbstractGestiune() = default;
    friend istream& operator>>(istream& input, AbstractGestiune& p);
    friend ostream& operator<<(ostream& output, const AbstractGestiune& p);
    virtual istream& read(istream& input);
    virtual ostream& write(ostream& output) const;
};

