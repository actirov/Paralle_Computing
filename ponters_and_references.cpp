#include <iostream>
using namespace std;

int main() {

    // Referencia o Alias
    int dato = 100;
    int &referencia = dato;

    cout << dato << " " << &dato << "\n"
         << referencia << " " << &referencia << "\n";
    referencia = 200;
    cout << dato << " " << &dato << "\n"
         << referencia << " " << &referencia << "\n";

    int valor =10;
    int* apuntador = &valor;

    cout << valor << " " << &valor << "\n"
         << apuntador << " " << &apuntador << " " << *apuntador << "\n";

    *apuntador = 20;
    cout << valor << " " << &valor << "\n"
         << apuntador << " " << &apuntador << " " << *apuntador << "\n";

    return 0;
}