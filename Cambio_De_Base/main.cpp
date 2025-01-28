#include <iostream>
#include <string>
#include "conversiones.h"

using namespace std;

// Función para mostrar el menú principal
void mostrar_menu() {
    cout << "\n=== Menú de Conversión ===" << endl;
    cout << "1. Binario a Decimal" << endl;
    cout << "2. Binario a Hexadecimal" << endl;
    cout << "3. Decimal a Hexadecimal" << endl;
    cout << "4. Hexadecimal a Decimal" << endl;
    cout << "5. Corrimiento Binario (Izquierda o Derecha)" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;

    do {
        mostrar_menu();
        cin >> opcion;

        switch (opcion) {
            case 1: { // Binario a Decimal
                string binario;
                cout << "Ingrese un número binario: ";
                cin >> binario;
                cout << "Decimal: " << binario_a_decimal(binario) << endl;
                break;
            }
            case 2: { // Binario a Hexadecimal
                string binario;
                cout << "Ingrese un número binario: ";
                cin >> binario;
                cout << "Hexadecimal: " << binario_hexadecimal(binario) << endl;
                break;
            }
            case 3: { // Decimal a Hexadecimal
                int decimal;
                cout << "Ingrese un número decimal: ";
                cin >> decimal;
                cout << "Hexadecimal: " << decimal_a_hexadecimal(decimal) << endl;
                break;
            }
            case 4: { // Hexadecimal a Decimal
                string hexadecimal;
                cout << "Ingrese un número hexadecimal: ";
                cin >> hexadecimal;
                cout << "Decimal: " << hexadecimal_a_decimal(hexadecimal) << endl;
                break;
            }
            case 5: { // Corrimiento Binario
                string binario;
                char direccion;
                int posiciones;

                cout << "Ingrese un número binario: ";
                cin >> binario;
                cout << "Tipo de corrimiento (I para izquierda, D para derecha): ";
                cin >> direccion;
                cout << "Número de posiciones a desplazar: ";
                cin >> posiciones;

                try {
                    string resultado = corrimiento_binario(binario, direccion, posiciones);
                    cout << "Resultado después del corrimiento: " << resultado << endl;
                } catch (const invalid_argument &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 6: // Salir
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}
