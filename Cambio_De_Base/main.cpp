#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaraciones de funciones externas
extern char* decimal_a_hexadecimal(int decimal);
extern int hexadecimal_a_decimal(const char* hexadecimal);
extern int binario_a_decimal(const char* binario);
extern char* binario_a_hexadecimal(const char* binario);
extern void corrimiento_izquierda(char* binario, int posiciones);
extern void corrimiento_derecha(char* binario, int posiciones);

// Función para mostrar el menú principal
void mostrar_menu() {
    printf("\n=== Conversión y Operaciones Numéricas ===\n");
    printf("1. Binario a Decimal\n");
    printf("2. Binario a Hexadecimal\n");
    printf("3. Decimal a Hexadecimal\n");
    printf("4. Hexadecimal a Decimal\n");
    printf("5. Corrimiento a la izquierda\n");
    printf("6. Corrimiento a la derecha\n");
    printf("7. Salir\n");
    printf("Seleccione una opción: ");
}

int main() {
    int opcion;
    do {
        mostrar_menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char binario[65];
                printf("Ingrese un número binario: ");
                scanf("%s", binario);
                int resultado = binario_a_decimal(binario);
                printf("El equivalente en decimal es: %d\n", resultado);
                break;
            }
            case 2: {
                char binario[65];
                printf("Ingrese un número binario: ");
                scanf("%s", binario);
                char* resultado = binario_a_hexadecimal(binario);
                printf("El equivalente en hexadecimal es: %s\n", resultado);
                free(resultado); // Liberar memoria
                break;
            }
            case 3: {
                int decimal;
                printf("Ingrese un número decimal: ");
                scanf("%d", &decimal);
                char* resultado = decimal_a_hexadecimal(decimal);
                printf("El equivalente en hexadecimal es: %s\n", resultado);
                free(resultado); // Liberar memoria
                break;
            }
            case 4: {
                char hexadecimal[65];
                printf("Ingrese un número hexadecimal: ");
                scanf("%s", hexadecimal);
                int resultado = hexadecimal_a_decimal(hexadecimal);
                printf("El equivalente en decimal es: %d\n", resultado);
                break;
            }
            case 5: {
                char binario[65];
                int posiciones;
                printf("Ingrese un número binario: ");
                scanf("%s", binario);
                printf("Ingrese el número de posiciones a desplazar: ");
                scanf("%d", &posiciones);
                corrimiento_izquierda(binario, posiciones);
                printf("Resultado después del corrimiento a la izquierda: %s\n", binario);
                break;
            }
            case 6: {
                char binario[65];
                int posiciones;
                printf("Ingrese un número binario: ");
                scanf("%s", binario);
                printf("Ingrese el número de posiciones a desplazar: ");
                scanf("%d", &posiciones);
                corrimiento_derecha(binario, posiciones);
                printf("Resultado después del corrimiento a la derecha: %s\n", binario);
                break;
            }
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 7);

    return 0;
}
