#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> myStack;
    int opcja = -1;
    int przypadek;

    cout << "--- PROGRAM: ZARZADZANIE STOSEM ---" << endl;

    while (opcja != 0) {
        cout << "\n===============================" << endl;
        cout << "Wybierz akcje:" << endl;
        cout << "1. Dodaj przypadek na stos (PUSH)" << endl;
        cout << "2. Odejmij przypadek ze stosu (POP)" << endl;
        cout << "3. Sprawdz co jest na szczycie (PEEK)" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "===============================" << endl;
        cout << "Twoj wybor: ";
        cin >> opcja;

        switch (opcja) {
            case 1:
                cout << "Podaj wartosc (liczbe) przypadku do dodania: ";
                cin >> przypadek;
                myStack.push(przypadek);
                cout << "Dodano " << przypadek << " na stos." << endl;
                break;

            case 2:
                if (myStack.getTopNode() == nullptr) {
                    myStack.pop();
                } else {
                    przypadek = myStack.pop();
                    cout << "Odejmowanie. Usunieto przypadek o wartosci: " << przypadek << endl;
                }
                break;

            case 3:
                if (myStack.getTopNode() == nullptr) {
                    myStack.peek();
                } else {
                    cout << "Na samym szczycie stosu znajduje sie: " << myStack.peek() << endl;
                }
                break;

            case 0:
                cout << "Koniec dzialania programu." << endl;
                break;

            default:
                cout << "Nieznana opcja. Sprobuj ponownie." << endl;
                break;
        }
    }

    return 0;
}
