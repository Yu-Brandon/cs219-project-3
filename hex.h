#include <iostream>
#include <string>

using namespace std;

class Hexadecimal{
private:
    string hexadecimal;
    uint32_t decimalNumber;
    uint32_t decimal;
    string hexadecimalNumber;

public:
    Hexadecimal(string hex);
    Hexadecimal(int dec);
    void changeToDecimal();
    void changeToHex();
    uint32_t returnDecimal();
    string returnHexadecimal();
};