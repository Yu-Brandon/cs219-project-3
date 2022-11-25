#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "hex.h"
using namespace std;

void addingHex(string, string);
void andHex(string, string);
void asrHex(string,string);
void lsrHex(string, string);
void lslHex(string, string);
void notHex(string);
void orrHex(string, string);
void subHex(string, string);
void xorHex(string, string);

int main(){
    string line;
    string operation;
    string num1;
    string num2;

    ifstream myfile ("test.txt");
    if(myfile.is_open()){
        while(getline(myfile,line)){

            istringstream iss (line);
            iss >> operation >> num1 >> num2;

            if(operation == "ADD"){
                addingHex(num1, num2);
            }
            else if(operation == "AND"){
                andHex(num1, num2);
            }
            else if(operation == "ASR"){
                asrHex(num1, num2);
            }
            else if(operation == "LSR"){
                lsrHex(num1, num2);
            }
            else if(operation == "LSL"){
                lslHex(num1, num2);
            }
            else if(operation == "NOT"){
                notHex(num1);
            }
            else if(operation == "ORR"){
                orrHex(num1, num2);
            }
            else if(operation == "SUB"){
                subHex(num1, num2);
            }
            else{
                xorHex(num1, num2);
            }
        }
        myfile.close();
    }


    return 0;
}

void addingHex(string number1, string number2){
    uint32_t addedTogether;
    Hexadecimal firstHex(number1);
    Hexadecimal secondHex(number2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    addedTogether = firstHex.returnDecimal() + secondHex.returnDecimal();
    if(addedTogether == 0){
        cout << "Adding " << number1 << " and " << number2 << " is equal to 0x0" << endl;
    }
    else{
        Hexadecimal decimal(addedTogether);
        decimal.changeToHex();

        cout << "Adding " << number1 << " and " << number2 << " is equal to " << decimal.returnHexadecimal() << endl;
    }
}

void andHex(string number1, string number2){
    uint32_t andTogether;
    Hexadecimal firstHex(number1);
    Hexadecimal secondHex(number2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    andTogether = firstHex.returnDecimal() & secondHex.returnDecimal();
    Hexadecimal decimal(andTogether);
    decimal.changeToHex();

    if(andTogether == 0){
        cout << number1 << " AND " << number2 << " is equal to 0x0" << endl;
    }      
    else{
        cout << number1 << " AND " << number2 << " is equal to " << decimal.returnHexadecimal() << endl;
    }
}

void asrHex(string number1, string number2){
    uint32_t asrNum;
    int shiftNum = number2[0] - 48;

    Hexadecimal hex(number1);
    hex.changeToDecimal();

    asrNum = hex.returnDecimal() >> shiftNum;
    Hexadecimal decimal(asrNum);
    decimal.changeToHex();

    cout << number1 << " ASR " << number2 << " times is equal to " << decimal.returnHexadecimal() << endl;
}

void lsrHex(string number1, string number2){
    uint32_t lsrNum;
    int shiftNum = number2[0] - 48;

    Hexadecimal hex(number1);
    hex.changeToDecimal();

    unsigned int uNumber = hex.returnDecimal();
    lsrNum = uNumber >> shiftNum;
    Hexadecimal decimal(lsrNum);
    decimal.changeToHex();

    cout << number1 << " LSR " << number2 << " times is equal to " << decimal.returnHexadecimal() << endl;
}


void lslHex(string number1, string number2){
    uint32_t lslNum;
    int shiftNum = number2[0] - 48;

    Hexadecimal hex(number1);
    hex.changeToDecimal();

    lslNum = hex.returnDecimal() << shiftNum;
    Hexadecimal decimal(lslNum);
    decimal.changeToHex();

    cout << number1 << " LSL " << number2 << " times is equal to " << decimal.returnHexadecimal() << endl;
}

void notHex(string number1){
    uint32_t notNumber;
    Hexadecimal number(number1);
    number.changeToDecimal();

    notNumber = (~(number.returnDecimal()));
    Hexadecimal decimal(notNumber);
    decimal.changeToHex();

    if(notNumber == 0){
        cout << "Not of " << number1 << " is 0x0 "<< endl;
    }      
    else{
        cout << "Not of " << number1 << " is " << decimal.returnHexadecimal() << endl;
    }
}

void orrHex(string number1, string number2){
    uint32_t orrTogether;
    Hexadecimal firstHex(number1);
    Hexadecimal secondHex(number2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    orrTogether = firstHex.returnDecimal() | secondHex.returnDecimal();
    Hexadecimal decimal(orrTogether);
    decimal.changeToHex();

    if(orrTogether == 0){
        cout << number1 << " ORR " << number2 << " is equal to 0x0" << endl;
    }      
    else{
        cout << number1 << " ORR " << number2 << " is equal to " << decimal.returnHexadecimal() << endl;
    }
}

void subHex(string number1, string number2){
    uint32_t subTogether;
    Hexadecimal firstHex(number1);
    Hexadecimal secondHex(number2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    subTogether = firstHex.returnDecimal() - secondHex.returnDecimal();
    Hexadecimal decimal(subTogether);
    decimal.changeToHex();

    if(subTogether == 0){
        cout << "Subtracting " << number1 << " and " << number2 << " is equal to 0x0" << endl;
    }
    else{
        Hexadecimal decimal(subTogether);
        decimal.changeToHex();

        cout << "Subtracting " << number1 << " and " << number2 << " is equal to " << decimal.returnHexadecimal() << endl;
    }
}

void xorHex(string number1, string number2){
    uint32_t xorTogether;
    Hexadecimal firstHex(number1);
    Hexadecimal secondHex(number2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    xorTogether = firstHex.returnDecimal() ^ secondHex.returnDecimal();
    Hexadecimal decimal(xorTogether);
    decimal.changeToHex();

    if(xorTogether == 0){
        cout << number1 << " XOR " << number2 << " is equal to 0x0" << endl;
    }      
    else{
        cout << number1 << " XOR " << number2 << " is equal to " << decimal.returnHexadecimal() << endl;
    }
}