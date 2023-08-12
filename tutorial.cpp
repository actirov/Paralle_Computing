#include <iostream>
using namespace std;
int main(int argc, char** argv) {

    if (argc == 1 ){

        cout << "No pasaste parámetros " << argv[0];
        return 0;

    } else{

        for (int i =0; i< argc; i++){

            cout << "param " << i << " " << argv[i] << "\n";

        }

    }
    return 0;
}