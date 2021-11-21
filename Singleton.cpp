#include "Singleton.h"

ArrayOfObjects::~ArrayOfObjects() {
	for (auto& it : Get().arr) {
		delete it;
	}
	Get().arr.clear();
}

ArrayOfObjects& ArrayOfObjects::Get() {
	static ArrayOfObjects instance;
	return instance;
}

// Metoda add adauga un pointer in vector
void ArrayOfObjects::add(AbstractGestiune* x) {
	Get().arr.push_back(x);
}

// Metoda printArr afiseaza obiectele catre care arata pointerii vectorului
void ArrayOfObjects::printArr() {
	cout << "Numar plati: " << Get().arr.size() << '\n';
	int i = 1;
	for (auto& it : Get().arr) {
		cout << "\nPlata numarul " << i++ << ":\n" << *it;
	}
}

//Metoda returneaza id-ul platii pentru tipul Cash sau Chack si id-ul clientului pentru Card
void ArrayOfObjects::idPlataClient() {
	for (auto& it : Get().arr) {
		cout << "Tipul de plata: ";
		Gestiune<Card_Payment>* x = dynamic_cast<Gestiune<Card_Payment>*>(it);
		if (x) {
			cout << "Plata Card, id client: " << x->getClientId() << '\n';
		}
		else {
			Gestiune<Check_Payment>* y = dynamic_cast<Gestiune<Check_Payment>*>(it);
			if (y) {
				cout << "Plata Check, id plata: " << y->getIdPlata() << '\n';
			}
			else {
				Gestiune<Cash_Payment>* z = static_cast<Gestiune<Cash_Payment>*>(it);
				if (z) {
					cout << "Plata Cash, id plata: " << z->getIdPlata() << '\n';
				}
			}
		}
	}
}
