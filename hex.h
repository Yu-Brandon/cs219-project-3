#include <iostream>
#include <string>

using namespace std;

//the hexadecimal class that is used to convert hex to decimal and vice versa
class Hexadecimal{
private:
    //private varibales that will hold values that are passed in along with the value tbey are converted to
    string hexadecimal;
    uint32_t decimalNumber;
    uint32_t decimal;
    string hexadecimalNumber;

public:
    //constructor for when a string is used to instantiate the class
    Hexadecimal(string hex);
    //overloaded constructor for when int is used to instantiate the class
    Hexadecimal(int dec);
    //converts a hexadecimal number into a decimal number
    void changeToDecimal();
    //comverts a decimal number into a hexadecimal
    void changeToHex();
    //returns the decimal number to where it was called from
    uint32_t returnDecimal();
    //returns the hexadecimal number to where it was called from
    string returnHexadecimal();
};