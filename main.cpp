#include <iostream>
#include <string>
#include "Stack.h"
#include "FullStackException.h"

using namespace std;

int main() {
    Stack<int> myStack;
    int opcja = -1;
    int przypadek;
    int currentSize = 0;
    const int maxSize = 5;

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

    try {
            switch (opcja) {
                case 1:
                    cout << "Podaj wartosc przypadku do dodania: ";
                    cin >> przypadek;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Nieprawidlowe dane wejsciowe." << endl;
                    } else {
                        if (currentSize >= maxSize) {
                            throw FullStackException();
                        }
                        myStack.push(przypadek);
                        currentSize++;
                        cout << "Dodano " << przypadek << " na stos." << endl;
                    }
                    break;
                case 2:
                    if (myStack.getTopNode() == nullptr) {
                        myStack.pop();
                    } else {
                        przypadek = myStack.pop();
                        currentSize--;
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
                    if (opcja != -1) {
                        cout << "Nieznana opcja. Sprobuj ponownie." << endl;
                    }
                    break;
            }
        }
        catch (const EmptyStackException& e) {
            cout << e.what() << endl;
        }
        catch (const FullStackException& e) {
            cout << e.what() << endl;
        }
        catch (const std::bad_alloc& e) {
            cout << "Blad krytyczny: Brak pamieci operacyjnej!" << endl;
        }
        catch (const std::exception& e) {
            cout << "Wystapil nieoczekiwany blad: " << e.what() << endl;
        }
        catch (...) {
            cout << "Wystapil nieznany blad krytyczny!" << endl;
        }
    }

    return 0;
}
