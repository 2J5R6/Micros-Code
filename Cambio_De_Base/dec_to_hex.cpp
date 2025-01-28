#include <iostream> // Para la entrada y salida estándar
#include <string>   // Para manejar cadenas

using namespace std;

// Función para convertir un número decimal a hexadecimal
string decimal_a_hexadecimal(int decimal) {
    // Uso una cadena para construir el resultado
    string hexadecimal = "";

    // Defino un array con los caracteres hexadecimales
    char hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Mientras el número decimal sea mayor a 0, calculo los restos
    while (decimal > 0) {
        int residuo = decimal % 16;           // Obtengo el residuo de la división entre 16
        hexadecimal = hex_chars[residuo] + hexadecimal; // Inserto el carácter correspondiente al principio de la cadena
        decimal /= 16;                       // Divido el número entre 16 para calcular el siguiente dígito
    }

    // Si el número original era 0, devuelvo "0"
    if (hexadecimal == "") {
        hexadecimal = "0";
    }

    return hexadecimal; // Devuelvo la cadena hexadecimal construida
}

// int main() {
//     // Solicito al usuario un número decimal
//     int numero_decimal;
//     cout << "Ingrese un número en base decimal: ";
//     cin >> numero_decimal;

//     // Verifico que el número ingresado sea no negativo
//     if (numero_decimal < 0) {
//         cout << "Por favor, ingrese un número no negativo." << endl;
//         return 1; // Termino el programa con un código de error
//     }

//     // Llamo a la función para convertir el número a hexadecimal
//     string resultado = decimal_a_hexadecimal(numero_decimal);

//     // Muestro el resultado de la conversión
//     cout << "El equivalente en hexadecimal es: " << resultado << endl;

//     return 0; // Termino el programa exitosamente
// }
