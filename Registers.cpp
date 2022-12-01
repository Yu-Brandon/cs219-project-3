#include "Registers.h"

Registers::Registers(){
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
    if(registerNum == "R0" || "r0" || "R0," || "r0,"){
        RZero = hex;
    }
    else if(registerNum == "R1" || "r1" || "R1," || "r1,"){
        ROne = hex;
    }
    else if(registerNum == "R2" || "r2" || "R2," || "r2,"){
        RTwo = hex;
    }
    else if(registerNum == "R3" || "r3" || "R3," || "r3,"){
        RThree = hex;
    }
    else if(registerNum == "R4" || "r4" || "R4," || "r4,"){
        RFour = hex;
    }
    else if(registerNum == "R5" || "r5" || "R5," || "r5,"){
        RFive = hex;
    }
    else if(registerNum == "R6" || "r6" || "R6," || "r6,"){
        RSix = hex;
    }
    else{
        RSeven = hex;
    }
}

string Registers::returnRegister(string registerNum){
    if(registerNum == "R0" || "r0" || "R0," || "r0,"){
      return RZero;
    }
    else if(registerNum == "R1" || "r1"|| "R1," || "r1,"){
      return ROne;
    }
    else if(registerNum == "R2" || "r2"|| "R2," || "r2,"){
      return RTwo;
    }
    else if(registerNum == "R3" || "r3"|| "R3," || "r3,"){
        return RThree;
    }
    else if(registerNum == "R4" || "r4"|| "R4," || "r4,"){
       return RFour;
    }
    else if(registerNum == "R5" || "r5"|| "R5," || "r5,"){
       return RFive;
    }
    else if(registerNum == "R6" || "r6"|| "R6," || "r6,"){
      return RSix;
    }
    else{
        return RSeven;
    }
}

void Registers::printRegisters(){
    cout << "R0:" << RZero << "  " << "R1:" << ROne << "  " << "R2:" << RTwo << "  " << "R3:" << RThree << "  "  << endl 
    << "R4:" << RFour << "  " << "R5:" << RFive << "  " << "R6:" << RSix << "  " << "R7:" << RSeven << endl;
}