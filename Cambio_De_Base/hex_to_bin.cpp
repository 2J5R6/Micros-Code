//this is the code for converting a hex number to bin number 

//All licenses are intended to be open source.

//Developer: Andres Garcia

#include <iostream>
#include <string>
using namespace std;


class Hex_to_Bin {
public:

    string convertirHexABinario(const string & hex) {
        string binario = "";
        for (char c : hex) {
            binario += hexADigitoBinario(c);
        }
        return binario;
    }

private:

    string hexADigitoBinario(char hexChar) {
        switch (toupper(hexChar)) {
            case '0': return "0000";
            case '1': return "0001";
            case '2': return "0010";
            case '3': return "0011";
            case '4': return "0100";
            case '5': return "0101";
            case '6': return "0110";
            case '7': return "0111";
            case '8': return "1000";
            case '9': return "1001";
            case 'A': return "1010";
            case 'B': return "1011";
            case 'C': return "1100";
            case 'D': return "1101";
            case 'E': return "1110";
            case 'F': return "1111";
            default: return ""; 
        }
    }
};

// int main() {
//     string numeroHex;
//     cout << "Ingrese un número hexadecimal: ";
//     cin >> numeroHex;

//     Hex_to_Bin conversor;

//     string numeroBinario = conversor.convertirHexABinario(numeroHex);
//     if (numeroBinario.empty()) {
//         cout << "El número hexadecimal ingresado es inválido." << endl;
//     } else {
//         cout << "El número en binario es: " << numeroBinario << endl;
//     }

//     return 0;
// }