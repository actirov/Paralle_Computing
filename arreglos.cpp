#include <iostream>
using namespace std;

int main(){

    const int tamanio = 10;

    int numeros[tamanio];

    // Te da el tamaño del arreglo en terminos de bytes, cada 
    // entero tiene 4 bytes 
    cout << "Tamanio del arreglo " << sizeof(numeros)/sizeof(int) << "\nlen";

    int* numeros2 = new int[tamanio];
    

    for (int i = 0; i<tamanio; i++){

        numeros[i] = i;
        numeros2[i] = i;
        cout << numeros[i] << " " << numeros2[i] << "\n";
    }

    delete[] numeros2; 


    return 0;
}