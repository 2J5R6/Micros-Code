#include <iostream> // Para la entrada y salida estándar
#include <string>   // Para manejar cadenas
#include <cmath>    // Para calcular potencias

using namespace std;

// Función para convertir un carácter hexadecimal a su valor decimal
int hex_char_a_decimal(char hex_char) {
    // Convierto el carácter en su equivalente decimal
    if (hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0'; // '0' tiene un valor ASCII base
    } else if (hex_char >= 'A' && hex_char <= 'F') {
        return 10 + (hex_char - 'A'); // 'A' comienza en 10
    } else if (hex_char >= 'a' && hex_char <= 'f') {
        return 10 + (hex_char - 'a'); // Manejo minúsculas también
    } else {
        // Si no es un carácter hexadecimal válido, devuelvo -1
        return -1;
    }
}

// Función para convertir un número hexadecimal a decimal
int hexadecimal_a_decimal(const string &hexadecimal) {
    int decimal = 0; // Inicializo el valor decimal
    int longitud = hexadecimal.length(); // Longitud de la cadena hexadecimal

    // Recorro cada carácter del número hexadecimal de derecha a izquierda
    for (int i = 0; i < longitud; i++) {
        char hex_char = hexadecimal[longitud - 1 - i]; // Obtengo el carácter actual desde la derecha
        int valor_decimal = hex_char_a_decimal(hex_char); // Lo convierto a decimal

        // Verifico si el carácter era válido
        if (valor_decimal == -1) {
            cout << "Carácter hexadecimal no válido: " << hex_char << endl;
            return -1; // Retorno error si hay un carácter inválido
        }

        // Calculamos el valor decimal acumulado
        decimal += valor_decimal * pow(16, i); // Multiplico por la potencia de 16 correspondiente
    }

    return decimal; // Devuelvo el valor decimal resultante
}

// int main() {
//     // Solicito al usuario un número hexadecimal
//     string numero_hexadecimal;
//     cout << "Ingrese un número hexadecimal: ";
//     cin >> numero_hexadecimal;

//     // Llamo a la función para realizar la conversión
//     int resultado = hexadecimal_a_decimal(numero_hexadecimal);

//     // Si hubo un error, termino el programa
//     if (resultado == -1) {
//         cout << "Error en la conversión. Por favor, intente de nuevo." << endl;
//         return 1;
//     }

//     // Muestro el resultado de la conversión
//     cout << "El equivalente en decimal es: " << resultado << endl;

//     return 0; // Termino el programa exitosamente
// }
