#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Función para convertir una cadena binaria a un número decimal
int binario_a_decimal(const string &binario) {
    int decimal = 0;
    int longitud = binario.length();
    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '1') {
            decimal += pow(2, longitud - 1 - i);
        }
    }
    return decimal;
}

// Función para convertir un número decimal a una cadena hexadecimal
string decimal_a_hexadecimal(int decimal) {
    string hexadecimal = "";
    string hex_chars = "0123456789ABCDEF";
    while (decimal > 0) {
        int residuo = decimal % 16;
        hexadecimal = hex_chars[residuo] + hexadecimal; // Para agregar cifra más significativa al principio
        decimal /= 16;
    }
    return hexadecimal.empty() ? "0" : hexadecimal;
}

// Función principal para convertir binario a hexadecimal
string binario_a_hexadecimal(const string &binario) { // Paso parámetro por referencia (&) -> Evita copiar el parámetro, minimiza el uso de memoria. (Si no se usa referencia, se copia el parámetro y se almacena en otro espacio de memoria, si se usa referencia, se almacena en el mismo espacio de memoria)
    int decimal = binario_a_decimal(binario);
    return decimal_a_hexadecimal(decimal);
}

int main() {
    string binario;
    cout << "Ingrese un número binario: ";
    cin >> binario;

    // Validar que el binario sea válido
    for (char c : binario) {
        if (c != '0' && c != '1') {
            cout << "Entrada inválida. Solo se permiten dígitos 0 y 1." << endl;
            return 1;
        }
    }

    string hexadecimal = binario_a_hexadecimal(binario);
    cout << "El número hexadecimal es: " << hexadecimal << endl;

    return 0;
}
