

//this is the code for converting a bin number to decinal number 

//All licenses are intended to be open source.

//Developer: Daniel García Araque


#include <iostream>
#include<cmath>

using namespace std;

//global variables 
int bin=0;
int num=0;

int asknumber(){
    cout << "Introduce un número binario: ";
    cin >> num;
    return num;

}

//calculate number

int calculate(int num){
    int decimalNumber = 0;
    int base = 1;
    int temp = num;
    
    while (temp) {
        int lastDigit = temp % 10;
        temp = temp / 10;
        decimalNumber += lastDigit * base;
        base = base * 2;
    }
    
    cout << "The number is " << decimalNumber << endl;
    return decimalNumber;
}

int main() {

    bin=asknumber();
    
    cout<<bin<<endl;
    
    calculate(bin);
   


    return 0;
}