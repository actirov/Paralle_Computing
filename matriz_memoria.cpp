#include <iostream>
using namespace std;
int main() {
    const int ren = 2;
    const int col = 4;

    int** matriz = new int*[ren];

    for (int i =0; i< ren; i++){
        matriz[i] = new int[col];

    }

    int contador = 0;
    cout << *matriz << "\n" ;
    for (int i=0; i<ren; i++){
        cout << matriz[i] << "\n" ;
        for (int j = 0; j<col; j++){
            cout << matriz[i][j] << "\n" ;
            matriz[i][j] = contador;
            contador++;
            ///cout << matriz[i][j] << "\n";

        }
        cout << "\n";

    }

    for (int i =0; i< ren; i++){
    delete[] matriz[i];
    }
    delete[] matriz;


    return 0;


}