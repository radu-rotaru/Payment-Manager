#include "AbstractGestiune.h"

// Supraincarcarea operatorului '>>'
istream& operator>>(istream& input, AbstractGestiune& p) {
    return p.read(input);
}

// Supraincarcarea operatorului '<<'
ostream& operator<<(ostream& output, const AbstractGestiune& p) {
    return p.write(output);
}

// Functia virtuala pentru citirea obiectelor
istream& AbstractGestiune::read(istream& input) {
    return input;
}

// Functia virtuala pentru afisarea obiectelor
ostream& AbstractGestiune::write(ostream& output) const {
    return output;
}
