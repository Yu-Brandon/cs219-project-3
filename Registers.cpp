#include "Registers.h"

//constructor
Registers::Registers(){
    //sets all the registers to the hex value of 0
    RZero = "0x0";
    ROne = "0x0";
    RTwo = "0x0";
    RThree = "0x0";
    RFour = "0x0";
    RFive = "0x0";
    RSix = "0x0";
    RSeven = "0x0";
}

void Registers::updateRegister(string registerNum, string hex){
    //finds the register that is passed in and updates that register to the hex number that was passed in
    if(registerNum == "R0" || registerNum == "r0" || registerNum == "R0," || registerNum == "r0,"){
        RZero = hex;
    }
    else if(registerNum == "R1" || registerNum == "r1" || registerNum == "R1," || registerNum == "r1,"){
        ROne = hex;
    }
    else if(registerNum == "R2" || registerNum == "r2" || registerNum == "R2," || registerNum == "r2,"){
        RTwo = hex;
    }
    else if(registerNum == "R3" || registerNum == "r3" || registerNum == "R3," || registerNum == "r3,"){
        RThree = hex;
    }
    else if(registerNum == "R4" || registerNum == "r4" || registerNum == "R4," || registerNum == "r4,"){
        RFour = hex;
    }
    else if(registerNum == "R5" || registerNum == "r5" || registerNum == "R5," || registerNum == "r5,"){
        RFive = hex;
    }
    else if(registerNum == "R6" || registerNum == "r6" || registerNum == "R6," || registerNum == "r6,"){
        RSix = hex;
    }
    else{
        RSeven = hex;
    }
}

string Registers::returnRegister(string registerNum){
    //finds the register that was passed in and then returns the hex number in that register
    if(registerNum == "R0" || registerNum == "r0" || registerNum == "R0," || registerNum == "r0,"){ 
        return RZero;
    }
    else if(registerNum == "R1" || registerNum == "r1"|| registerNum == "R1," || registerNum == "r1,"){
        return ROne;
    }
    else if(registerNum == "R2" || registerNum == "r2"|| registerNum == "R2," || registerNum == "r2,"){
        return RTwo;
    }
    else if(registerNum == "R3" || registerNum == "r3"|| registerNum == "R3," || registerNum == "r3,"){
        return RThree;
    }
    else if(registerNum == "R4" || registerNum == "r4"|| registerNum == "R4," || registerNum == "r4,"){
        return RFour;
    }
    else if(registerNum == "R5" || registerNum == "r5"|| registerNum == "R5," || registerNum == "r5,"){
        return RFive;
    }
    else if(registerNum == "R6" || registerNum == "r6"|| registerNum == "R6," || registerNum == "r6,"){
        return RSix;
    }
    else{
        return RSeven;
    }
}

void Registers::printRegisters(){
    //prints out the register number along with the hex number that is in that register
    cout << "R0:" << RZero << "  " << "R1:" << ROne << "  " << "R2:" << RTwo << "  " << "R3:" << RThree << "  "  << endl 
    << "R4:" << RFour << "  " << "R5:" << RFive << "  " << "R6:" << RSix << "  " << "R7:" << RSeven << endl;
}