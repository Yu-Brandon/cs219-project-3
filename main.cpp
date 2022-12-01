#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "hex.h"
#include "Registers.h"
using namespace std;

void addingHex(string, string, string, string, Registers*);
void movHex(string, string, string, Registers*);
void subHex(string, string, string, string, Registers*);
void orrHex(string, string, string, string, Registers*);
void xorHex(string, string, string, string, Registers*);
/*void andHex(string, string);
void asrHex(string,string);
void lsrHex(string, string);
void lslHex(string, string);
void notHex(string);
*/

int main(){
    Registers* myRegisters = new Registers();
    string line;
    string One, Two, Three, Four;

    ifstream myfile ("test.txt");
    if(myfile.is_open()){
        while(getline(myfile,line)){

            istringstream iss (line);
            iss >> One >> Two >> Three >> Four;

            if(One == "ADD" || One == "add"){
                addingHex(One, Two, Three, Four, myRegisters);
            }
            else if(One == "MOV" || One == "mov"){
                movHex(One, Two, Three, myRegisters);
            }
            else if(One == "SUB" || One == "sub"){
                subHex(One, Two, Three, Four, myRegisters);
            }
            else if(One == "ORR" || One == "orr"){
                orrHex(One, Two, Three, Four, myRegisters);
            }
            else if(One == "XOR" || One == "xor"){
                xorHex(One, Two, Three, Four, myRegisters);
            }
            /*else if(operation == "ASR"){
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
            else{
                xorHex(num1, num2);
            }*/
        }
        myfile.close();
    }


    return 0;
}

void movHex(string One, string Two, string Three, Registers* myRegisters){
    myRegisters -> updateRegister(Two, Three);
    cout << One << " " << Two << " " << Three << " " << endl;
    myRegisters -> printRegisters();
}

void addingHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    uint32_t addedTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    addedTogether = firstHex.returnDecimal() + secondHex.returnDecimal();
    Hexadecimal decimal(addedTogether);
    decimal.changeToHex();

    if(addedTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
}


void subHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    uint32_t addedTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    addedTogether = firstHex.returnDecimal() - secondHex.returnDecimal();
    Hexadecimal decimal(addedTogether);
    decimal.changeToHex();

    if(addedTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
}

void orrHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    uint32_t addedTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    addedTogether = firstHex.returnDecimal() | secondHex.returnDecimal();
    Hexadecimal decimal(addedTogether);
    decimal.changeToHex();

    if(addedTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
}

void xorHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    uint32_t addedTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();

    addedTogether = firstHex.returnDecimal() ^ secondHex.returnDecimal();
    Hexadecimal decimal(addedTogether);
    decimal.changeToHex();

    if(addedTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
}

/*void andHex(string number1, string number2){
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

*/