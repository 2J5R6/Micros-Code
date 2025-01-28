#ifndef CONVERSIONES_H
#define CONVERSIONES_H

#include <string>
using namespace std;

// Declaraciones de funciones
int binario_a_decimal(const string &binario);
string binario_hexadecimal(const string &binario);
string decimal_a_hexadecimal(int decimal);
int hexadecimal_a_decimal(const string &hexadecimal);
string corrimiento_binario(const string &binario, char direccion, int posiciones);


#endif
