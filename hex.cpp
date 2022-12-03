#include "hex.h"

//constructor for when string is used to instantiate the class
Hexadecimal::Hexadecimal(string hex){
    //sets the hexadecimal varibale in private to the hex that was passed in and decimal is set to zero
    hexadecimal = hex;
    decimalNumber = 0;
}

//constructor for when int is used to instantiaate the class
Hexadecimal::Hexadecimal(int dec){
    //sets the decimal varibale in the private class to the decimal that was passed in and makes sure the hexadecimal bumber is empty
    decimal = dec;
    hexadecimalNumber = hexadecimalNumber.empty();
}

//function to change the hex string to decimal
void Hexadecimal::changeToDecimal(){
    hexadecimal.erase(0,2);
    //erases the 0x infront of the hexadecimal number
    int length = hexadecimal.size();
    //creates an int to holf the length of the hex number
    uint32_t power = 1;
    //creates a int to hold the power of which the number will be mutiplied by

    //for loop that goes from the back of the string til it hits the fronts (string = hexadecimal number)
    for(int i = length - 1; i >= 0; i--){
        //there is a difference between if the bit is 0-9 or A-F so a if is needed to check it
        if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9'){
            decimalNumber = decimalNumber + (uint32_t(hexadecimal[i]) - 48) * power;
            //if it is 0-9 we will change that character into a int through the ascii value and the multiplying by the power before adding it onto the deciamal number
            power = power * 16;
            //increments the power by a factor of 16 because hexadeciaml has a base of 16
        }

        else if(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F'){
            decimalNumber = decimalNumber + (uint32_t(hexadecimal[i]) - 55) * power;
            //if it is A-F we will change that character into a int through the ascii value and the multiplying by the power before adding it onto the deciamal number
            power = power * 16;
            //increments the power by a factor of 16 because hexadeciaml has a base of 16
        }
    }
}

//converts a decimal number into a hexadecimal string
void Hexadecimal::changeToHex(){
    string front = "0x";
    //creates a string to hold the 0x that is infront of a hex number

    //while loop that will go until the decimal number is 0 which would be when it is converted into a hex
    while(decimal != 0){
        int temp = 0;
        temp = decimal % 16;
        //creates a temp which will be equal to the remanider of the decimal number divided by 16 which would leave it being 1-16

        if (temp < 10) {
            string insert;
            insert += temp + 48;
            hexadecimalNumber.insert(0, insert);
            //if temp is less than ten we will just covert that integer into a charcter and then adds it to the begining of the string
        }

        else{
            string insert;
            insert += temp + 55;
            hexadecimalNumber.insert(0, insert);
            //if temp is between 10-16 it needs to be converted to a character so 55 is added onto it to change it from a decimal number to a hexadecicimal letter
            //then it is added onto the begining of the string
        }
        decimal = decimal/16;
        //we divide the decial number by 16 to reset the while loop
    }
    hexadecimalNumber.insert(0,front);
    //0x is added onto the front of the string
}

//returns the decimal number to where it was called from
uint32_t Hexadecimal::returnDecimal(){
    return decimalNumber;
}

//returns the hexadecimal number to where it was called from
string Hexadecimal::returnHexadecimal(){
    return hexadecimalNumber;
}