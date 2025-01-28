#include <iostream>
#include <cmath>
using namespace std;

int binario_a_decimal(const string &binario) {
    int decimal = 0, potencia = 0;
    for (int i = binario.length() - 1; i >= 0; i--) {
        decimal += (binario[i] - '0') * pow(2, potencia);
        potencia++;
    }
    return decimal;
}
