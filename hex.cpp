#include "hex.h"

Hexadecimal::Hexadecimal(string hex){
    hexadecimal = hex;
    decimalNumber = 0;
}

Hexadecimal::Hexadecimal(int dec){
    decimal = dec;
    hexadecimalNumber = hexadecimalNumber.empty();
}

void Hexadecimal::changeToDecimal(){
    hexadecimal.erase(0,2);
    int length = hexadecimal.size();
    uint32_t power = 1;

    for(int i = length - 1; i >= 0; i--){
        if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9'){
            decimalNumber = decimalNumber + (uint32_t(hexadecimal[i]) - 48) * power;

            power = power * 16;
        }

        else if(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F'){
            decimalNumber = decimalNumber + (uint32_t(hexadecimal[i]) - 55) * power;

            power = power * 16;
        }
    }
}

void Hexadecimal::changeToHex(){
    string front = "0x";
    while(decimal != 0){
        
        int temp = 0;
        temp = decimal % 16;

        if (temp < 10) {
            string insert;
            insert += temp + 48;
            hexadecimalNumber.insert(0, insert);
        }

        else{
            string insert;
            insert += temp + 55;
            hexadecimalNumber.insert(0, insert);
        }
        decimal = decimal/16;
    }
    hexadecimalNumber.insert(0,front);
    
}

uint32_t Hexadecimal::returnDecimal(){
    return decimalNumber;
}

string Hexadecimal::returnHexadecimal(){
    return hexadecimalNumber;
}