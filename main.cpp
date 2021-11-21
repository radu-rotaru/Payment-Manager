#include <iostream>
#include "Singleton.h"
#include "Factory.h"

using namespace std;

int main() {
	FactoryOfPayments factory;
	bool run = 1;
	int optiune;
	while (run) {
		cout << "Menu\nCititi plata(0)\nAfisati toate platile(1)\nAfisati id-ul platii daca plata este de tip Cash sau Check, si id-ul clientului daca este de tip Card(2)\nIesire(3)\n";
		cin >> optiune;
		switch (optiune) {
			case 0: {
				cout << "Introduceti tipul de plata:\n1 - Plata Cash\n2 - Plata Check\n3 - Plata Card\n";
				int tip;
				cin >> tip;
				AbstractGestiune* object = factory.createObject(tip);
				cin >> *object;
				ArrayOfObjects::add(object);
				break;
			}
			case 1: {
				ArrayOfObjects::printArr();
				break;
			}
			case 2: {
				ArrayOfObjects::idPlataClient();
				break;
			}
			default: {
				run = 0;
			}
		}
	}

	return 0;
}