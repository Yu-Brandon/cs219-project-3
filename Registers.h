#include<iostream>
#include<string>

using namespace std;

class Registers{
private:
    string RZero, ROne, RTwo, RThree, RFour, RFive, RSix, RSeven;
public:
    Registers();
    void updateRegister(string registerNum, string hex);
    string returnRegister(string regsiterNum);
    void printRegisters();
};