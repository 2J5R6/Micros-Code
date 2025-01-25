//this is the code for converting a bin number to decinal number 

//All licenses are intended to be open source.

//Developer: Daniel García Araque


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int bin, dec = 0, potencia = 0;
    cout << "Introduce un número binario: ";
    cin >> bin;
    while (bin > 0) {
        dec += (bin % 10) * pow(2, potencia);
        bin /= 10;
        potencia++;
    }
    cout << "El número decimal es: " << dec << endl;
    return 0;
}
