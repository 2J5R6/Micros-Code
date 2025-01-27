#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

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


// Declaraciones de funciones externas
extern char* decimal_a_hexadecimal(int decimal);
extern int hexadecimal_a_decimal(const char* hexadecimal);
extern int binario_a_decimal(const char* binario);
extern char* binario_a_hexadecimal(const char* binario);
extern void corrimiento_izquierda(char* binario, int posiciones);
extern void corrimiento_derecha(char* binario, int posiciones);

// Funciones de callback para los botones
void on_binario_a_decimal(GtkWidget *widget, gpointer data) {
    const char* binario = gtk_entry_get_text(GTK_ENTRY(data));
    int resultado = binario_a_decimal(binario);
    char buffer[65];
    sprintf(buffer, "El equivalente en decimal es: %d", resultado);
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void on_binario_a_hexadecimal(GtkWidget *widget, gpointer data) {
    const char* binario = gtk_entry_get_text(GTK_ENTRY(data));
    char* resultado = binario_a_hexadecimal(binario);
    char buffer[65];
    sprintf(buffer, "El equivalente en hexadecimal es: %s", resultado);
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    free(resultado);
}

void on_decimal_a_hexadecimal(GtkWidget *widget, gpointer data) {
    int decimal = atoi(gtk_entry_get_text(GTK_ENTRY(data)));
    char* resultado = decimal_a_hexadecimal(decimal);
    char buffer[65];
    sprintf(buffer, "El equivalente en hexadecimal es: %s", resultado);
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    free(resultado);
}

void on_hexadecimal_a_decimal(GtkWidget *widget, gpointer data) {
    const char* hexadecimal = gtk_entry_get_text(GTK_ENTRY(data));
    int resultado = hexadecimal_a_decimal(hexadecimal);
    char buffer[65];
    sprintf(buffer, "El equivalente en decimal es: %d", resultado);
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void on_corrimiento_izquierda(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char* binario = gtk_entry_get_text(GTK_ENTRY(entries[0]));
    int posiciones = atoi(gtk_entry_get_text(GTK_ENTRY(entries[1])));
    corrimiento_izquierda((char*)binario, posiciones);
    char buffer[65];
    sprintf(buffer, "Resultado después del corrimiento a la izquierda: %s", binario);
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void on_corrimiento_derecha(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char* binario = gtk_entry_get_text(GTK_ENTRY(entries[0]));
    int posiciones = atoi(gtk_entry_get_text(GTK_ENTRY(entries[1])));
    corrimiento_derecha((char*)binario, posiciones);
    char buffer[65];
    sprintf(buffer, "Resultado después del corrimiento a la derecha: %s", binario);
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Conversión y Operaciones Numéricas");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *label_binario = gtk_label_new("Número Binario:");
    gtk_grid_attach(GTK_GRID(grid), label_binario, 0, 0, 1, 1);
    GtkWidget *entry_binario = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_binario, 1, 0, 1, 1);

    GtkWidget *label_decimal = gtk_label_new("Número Decimal:");
    gtk_grid_attach(GTK_GRID(grid), label_decimal, 0, 1, 1, 1);
    GtkWidget *entry_decimal = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_decimal, 1, 1, 1, 1);

    GtkWidget *label_hexadecimal = gtk_label_new("Número Hexadecimal:");
    gtk_grid_attach(GTK_GRID(grid), label_hexadecimal, 0, 2, 1, 1);
    GtkWidget *entry_hexadecimal = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_hexadecimal, 1, 2, 1, 1);

    GtkWidget *label_posiciones = gtk_label_new("Número de Posiciones:");
    gtk_grid_attach(GTK_GRID(grid), label_posiciones, 0, 3, 1, 1);
    GtkWidget *entry_posiciones = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_posiciones, 1, 3, 1, 1);

    GtkWidget *button_binario_a_decimal = gtk_button_new_with_label("Binario a Decimal");
    g_signal_connect(button_binario_a_decimal, "clicked", G_CALLBACK(on_binario_a_decimal), entry_binario);
    gtk_grid_attach(GTK_GRID(grid), button_binario_a_decimal, 0, 4, 2, 1);

    GtkWidget *button_binario_a_hexadecimal = gtk_button_new_with_label("Binario a Hexadecimal");
    g_signal_connect(button_binario_a_hexadecimal, "clicked", G_CALLBACK(on_binario_a_hexadecimal), entry_binario);
    gtk_grid_attach(GTK_GRID(grid), button_binario_a_hexadecimal, 0, 5, 2, 1);

    GtkWidget *button_decimal_a_hexadecimal = gtk_button_new_with_label("Decimal a Hexadecimal");
    g_signal_connect(button_decimal_a_hexadecimal, "clicked", G_CALLBACK(on_decimal_a_hexadecimal), entry_decimal);
    gtk_grid_attach(GTK_GRID(grid), button_decimal_a_hexadecimal, 0, 6, 2, 1);

    GtkWidget *button_hexadecimal_a_decimal = gtk_button_new_with_label("Hexadecimal a Decimal");
    g_signal_connect(button_hexadecimal_a_decimal, "clicked", G_CALLBACK(on_hexadecimal_a_decimal), entry_hexadecimal);
    gtk_grid_attach(GTK_GRID(grid), button_hexadecimal_a_decimal, 0, 7, 2, 1);

    GtkWidget *button_corrimiento_izquierda = gtk_button_new_with_label("Corrimiento a la Izquierda");
    GtkWidget *entries_izquierda[2] = {entry_binario, entry_posiciones};
    g_signal_connect(button_corrimiento_izquierda, "clicked", G_CALLBACK(on_corrimiento_izquierda), entries_izquierda);
    gtk_grid_attach(GTK_GRID(grid), button_corrimiento_izquierda, 0, 8, 2, 1);

    GtkWidget *button_corrimiento_derecha = gtk_button_new_with_label("Corrimiento a la Derecha");
    GtkWidget *entries_derecha[2] = {entry_binario, entry_posiciones};
    g_signal_connect(button_corrimiento_derecha, "clicked", G_CALLBACK(on_corrimiento_derecha), entries_derecha);
    gtk_grid_attach(GTK_GRID(grid), button_corrimiento_derecha, 0, 9, 2, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}