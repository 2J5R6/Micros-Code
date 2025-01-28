#include <iostream>
#include <string>

using namespace std;

// Función para convertir una cadena binaria a un número decimal
int binarioa_decimal(const string &binario) {
    int decimal = 0;
    for (char bit : binario) {
        // Desplazo el valor acumulado a la izquierda y agrego el bit actual
        decimal = (decimal << 1) | (bit - '0');
    }
    return decimal;
}

// Función para convertir un número decimal a una cadena binaria
string decimala_binario(int decimal, int longitud_original) {
    string binario;
    for (int i = 0; i < longitud_original; i++) {
        // Añado el bit menos significativo al resultado
        binario = ((decimal & 1) ? '1' : '0') + binario;
        // Desplazo a la derecha el número para obtener el siguiente bit
        decimal >>= 1;
    }
    return binario;
}

// Función para realizar un corrimiento en una cadena binaria
string corrimiento_binario(const string &binario, char direccion, int posiciones) {
    // Convierto la cadena binaria a un número decimal
    int numero = binarioa_decimal(binario);
    int longitud_original = binario.length();

    if (direccion == 'I' || direccion == 'i') {
        // Corrimiento a la izquierda
        numero <<= posiciones;

        // Uso una máscara para limitar el resultado a la longitud original
        int mascara = (1 << longitud_original) - 1;
        numero &= mascara; // Esto descarta los bits que excedan la longitud original
    } else if (direccion == 'D' || direccion == 'd') {
        // Corrimiento a la derecha
        numero >>= posiciones;
    } else {
        throw invalid_argument("Dirección de corrimiento no válida.");
    }

    // Convierto el resultado de vuelta a una cadena binaria con la longitud original
    return decimala_binario(numero, longitud_original);
}






//!Version con MAIN----------------------
// #include <iostream>
// #include <string>

// using namespace std;

// // Función para convertir una cadena binaria a un número decimal
// int binario_a_decimal(const string &binario) {
//     int decimal = 0;
//     for (char bit : binario) {
//         //   Desplazo el valor acumulado a la izquierda y agrego el bit actual
//         decimal = (decimal << 1) | (bit - '0');
//     }
//     return decimal;
// }

// // Función para convertir un número decimal a una cadena binaria
// string decimal_a_binario(int decimal, int longitud_original) {
//     string binario;
//     for (int i = 0; i < longitud_original; i++) {
//         //   Añado el bit menos significativo al resultado
//         binario = ((decimal & 1) ? '1' : '0') + binario;
//         // Desplazo a la derecha el número para obtener el siguiente bit
//         decimal >>= 1;
//     }
//     return binario;
// }

// int main() {
//     // Solicito al usuario que ingrese un número binario
//     string entrada_binaria;
//     cout << "Ingrese un número binario: ";
//     cin >> entrada_binaria;

//     // Guardo la longitud original del número binario
//     int longitud_original = entrada_binaria.length();

//     // Convierto la cadena binaria a un número decimal
//     int numero = binario_a_decimal(entrada_binaria);

//     // Pregunto al usuario el tipo de corrimiento
//     char direccion;
//     cout << "Tipo de corrimiento (I para izquierda, D para derecha): ";
//     cin >> direccion;

//     // Solicito al usuario el número de posiciones a desplazar
//     int posiciones;
//     cout << "Número de posiciones a desplazar: ";
//     cin >> posiciones;

//     // Realizo la operación de corrimiento según la dirección indicada
//     if (direccion == 'I' || direccion == 'i') {
//         //   Realizo el corrimiento a la izquierda
//         numero <<= posiciones;

//         // Uso una máscara para limitar el resultado a la longitud original
//         int mascara = (1 << longitud_original) - 1;
//         numero &= mascara; // Esto descarta los bits que excedan la longitud original
//     } else if (direccion == 'D' || direccion == 'd') {
//         //   Realizo el corrimiento a la derecha
//         numero >>= posiciones;
//     } else {
//         cout << "Dirección de corrimiento no válida." << endl;
//         return 1;
//     }

//     // Convierto el resultado de vuelta a una cadena binaria con la longitud original
//     string resultado_binario = decimal_a_binario(numero, longitud_original);

//     // Muestro el resultado al usuario
//     cout << "Resultado después del corrimiento: " << resultado_binario << endl;

//     return 0;
// }
