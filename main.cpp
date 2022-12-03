#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "hex.h"
#include "Registers.h"
using namespace std;

//All function Prototypes for the operations needed
void addingHex(string, string, string, string, Registers*);
void movHex(string, string, string, Registers*);
void subHex(string, string, string, string, Registers*);
void andHex(string, string, string, string, Registers*);
void orrHex(string, string, string, string, Registers*);
void xorHex(string, string, string, string, Registers*);
void asrHex(string, string, string, string, Registers*);
void lsrHex(string, string, string, string, Registers*);
void lslHex(string, string, string, string, Registers*);

int main(){
    //creating the register class that holds all of the registers
    Registers* myRegisters = new Registers();
    string line;
    //creating strings used to hold information read in from the file
    string One, Two, Three, Four;

    //opens the file and reads one line in at a time
    ifstream myfile ("test.txt");
    if(myfile.is_open()){
        while(getline(myfile,line)){
            
            //splits the line that is wrtitten where One holds the operations
            istringstream iss (line);
            iss >> One >> Two >> Three >> Four;

            if(One == "ADD" || One == "add"){
                addingHex(One, Two, Three, Four, myRegisters);
                //function call for adding two resistors if One (operation) is AND or and
            }
            else if(One == "MOV" || One == "mov"){
                movHex(One, Two, Three, myRegisters);
                //function call for Moving a number into a register if one (operation) is Mov or mov
            }
            else if(One == "SUB" || One == "sub"){
                subHex(One, Two, Three, Four, myRegisters);
                //function call for subtracting two resistors if one (operation) is SUB or sub
            }
            else if(One == "AND" || One == "and"){
                andHex(One, Two, Three, Four, myRegisters);
                //functoin call for bitwise And if One (operation) is AND or and
            }
            else if(One == "ORR" || One == "orr"){
                orrHex(One, Two, Three, Four, myRegisters);
                //functoin call for bitwise Or if One (operation) is ORR or orr
            }
            else if(One == "XOR" || One == "xor"){
                xorHex(One, Two, Three, Four, myRegisters);
                //functoin call for bitwise xor if One (operation) is XOR or xor
            }
            else if(One == "ASR" || One == "asr"){
                asrHex(One, Two, Three, Four, myRegisters);
                //functoin call for bitwise Asr if One (operation) is ASR or asr
            }
            else if(One == "LSR" || One == "lsr"){
                lsrHex(One, Two, Three, Four, myRegisters);
                //functoin call for bitwise lsr if One (operation) is LSR or lsr
            }
            else if(One == "LSL" || One == "lsl"){
                lslHex(One, Two, Three, Four, myRegisters);
                //functoin call for bitwise lsl if One (operation) is LSl or lsld
            }
        }
        myfile.close();
    }


    return 0;
}

//function for Moving
void movHex(string One, string Two, string Three, Registers* myRegisters){
    //Three holds string of the immidiate operator
    string nThree = Three;
    Three.erase(0,1);
    //erases the # from the begining of the string
    myRegisters -> updateRegister(Two, Three);
    //The resiguster that is being written to is in Two so we will pass in the register and the immidieate operand into the register
    //class so it can be updates
    cout << One << " " << Two << " " << nThree << " " << endl;
    myRegisters -> printRegisters();
    //the operation and all the registers are now printed to the screen
}

//function for adding two registers
void addingHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register that will be written too and Three and Four hold the operators
    uint32_t addedTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);
    //we set two string equal to the hex number in the two registers

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);

    firstHex.changeToDecimal();
    secondHex.changeToDecimal();
    //convert the two hex numbers into decimal using the hexadecimal class

    addedTogether = firstHex.returnDecimal() + secondHex.returnDecimal();
    Hexadecimal decimal(addedTogether);
    decimal.changeToHex();
    //add the two decimal numbers togther and then change that number into Hex

    if(addedTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    //write the added togther hexadecimal number into the register
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
    //print out the operation and all the registers to the screen
}

//function for subtracting two registers
void subHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register that is being written to and Three and Four hold the operators
    uint32_t subTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);
    //create two string to hold the hexadecimal in the two registers

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);
    firstHex.changeToDecimal();
    secondHex.changeToDecimal();
    //convert the two hex numbers into decimal using the hexadecimal class

    subTogether = firstHex.returnDecimal() - secondHex.returnDecimal();
    Hexadecimal decimal(subTogether);
    decimal.changeToHex();
    //Subtract the two decimal numbers and then turn it back into a hexadecimal using the hexadecimal class

    if(subTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    //update the register that is being written to with the hexadecimal of the two other registers subtracted
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
    //prints out the operation and all the registers to the screen
}

//function for bitwise and of two registers
void andHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register that is being written to and Three and Four hold the operators
    uint32_t andTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);
    //create two string to hold the hex numbers in the two registers

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);
    firstHex.changeToDecimal();
    secondHex.changeToDecimal();
    //using the hexadecimal class convert the hexadecimal numbers into decimal

    andTogether = firstHex.returnDecimal() & secondHex.returnDecimal();
    Hexadecimal decimal(andTogether);
    decimal.changeToHex();
    //do bitwise and to the decimal numbers and then using the hexadecimal class convert the decimal into hex

    if(andTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    //updates the hex number into the register being written to
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
    //prints out the opeartion and all the registers
}

//function for bitwise or of two registers
void orrHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register being written to and Three and Four are the operators
    uint32_t orrTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);
    //create two strings to hold the hex numbers in the two registers

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);
    firstHex.changeToDecimal();
    secondHex.changeToDecimal();
    //using the hexadecimal class to convert the hexadecimal numbers to decimal

    orrTogether = firstHex.returnDecimal() | secondHex.returnDecimal();
    Hexadecimal decimal(orrTogether);
    decimal.changeToHex();
    //do bitwise or to the numbers can then convert it back into hexadecimal using the hexadeciaml class

    if(orrTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    //updates the hex number into the register being written to
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
    //prints out the operation and all the registers
}

//function for bitwise Xor
void xorHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register being written to and Three and Four are the operators
    uint32_t xorTogether;
    string hex1, hex2;
    hex1 = myRegisters -> returnRegister(Three);
    hex2 = myRegisters -> returnRegister(Four);
    //creates two string to hold the hex numbers in the registers

    Hexadecimal firstHex(hex1);
    Hexadecimal secondHex(hex2);
    firstHex.changeToDecimal();
    secondHex.changeToDecimal();
    //using the hexadecimal class to comvert the hexadecimal numbers into decimal

    xorTogether = firstHex.returnDecimal() ^ secondHex.returnDecimal();
    Hexadecimal decimal(xorTogether);
    decimal.changeToHex();
    //do bitwise Xor and the convert the number back into hexadecimal using the hexadecimal class

    if(xorTogether == 0){
        myRegisters -> updateRegister(Two, "0x0");
    }
    else{
        myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    }
    //updateing the hexadecimal into the register being written to
    cout << One << " " << Two << " " << Three << " " << Four << endl;
    myRegisters -> printRegisters();
    //prints out the operation and all the registers
}

//function for bitwise asr
void asrHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register being written to Three holds the operator and Four holds how much to shift by
    uint32_t asrNum;
    string nFour = Four;
    Four.erase(0,1);
    //remove the # infront of the shift number
    int shiftNum = Four[0] - 48;
    //converts the shift character into a integer

    string hex1 = myRegisters -> returnRegister(Three);
    Hexadecimal hex(hex1);
    hex.changeToDecimal();
    //creates a string to hold the hex number in the register and then converts it into decimal using the hexadecimal class

    signed int uNumber = hex.returnDecimal();
    asrNum = (uNumber >> shiftNum);
    Hexadecimal decimal(asrNum);
    decimal.changeToHex();
    //creates a signed int because asr uses a signed int and then shifts the signed number and then changing it back hex using the hexadecimal class

    myRegisters -> updateRegister(Two, decimal.returnHexadecimal());
    //updates the hexadecimal into the register being written to
    cout << One << " " << Two << " " << Three << " " << nFour << endl;
    myRegisters -> printRegisters();
    //prints out the operation and all the registers
}

void lsrHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register being written to Three holds the operator and Four holds how much to shift by
    uint32_t lsrNum;
    string nFour = Four;
    Four.erase(0,1);
    //remove the # infront of the shift number
    int shiftNum = Four[0] - 48;
    //converts the shift character into a integer

    string hex1 = myRegisters -> returnRegister(Three);
    Hexadecimal hex(hex1);
    hex.changeToDecimal();
    //creates a string to hold the hex number in the register and then converts it into decimal using the hexadecimal class

    unsigned int uNumber = hex.returnDecimal();
    lsrNum = uNumber >> shiftNum;
    Hexadecimal decimal(lsrNum);
    decimal.changeToHex();
    //creates a unsigned because lsr uses a unsigned int and then shifts the signed number and then changing it back hex using the hexadecimal class

    myRegisters ->updateRegister(Two, decimal.returnHexadecimal());
    //updates the hexadecimal into the register being written to
    cout << One << " " << Two << " " << Three << " " << nFour << endl;
    myRegisters -> printRegisters();
    //prints out the operation and all the registers
}

void lslHex(string One, string Two, string Three, string Four, Registers* myRegisters){
    //Two holds the register being written to Three holds the operator and Four holds how much to shift by
    uint32_t lslNum;
    string nFour = Four;
    Four.erase(0,1);
    //remove the # infront of the shift number
    int shiftNum = Four[0] - 48;
    //converts the shift character into a integer

    string hex1 = myRegisters -> returnRegister(Three);
    Hexadecimal hex(hex1);
    hex.changeToDecimal();
    //creates a string to hold the hex number in the register and then converts it into decimal using the hexadecimal class

    lslNum = hex.returnDecimal() << shiftNum;
    Hexadecimal decimal(lslNum);
    decimal.changeToHex();
    //shifts the decimal number and then converts it into hexadecimal using the hexadecimal class

    myRegisters ->updateRegister(Two, decimal.returnHexadecimal());
    //updates the hexadecimal into the register being written to
    cout << One << " " << Two << " " << Three << " " << nFour << endl;
    myRegisters -> printRegisters();
    //prints out the operation and all the registers
}
