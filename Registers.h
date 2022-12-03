#include<iostream>
#include<string>

using namespace std;

//Register class that is used to hold, update, return, and print the registers
class Registers{
private:
    //creation of all the registers as itemtype string
    string RZero, ROne, RTwo, RThree, RFour, RFive, RSix, RSeven;
public:
    //constrcutor
    Registers();
    //updates the registers
    void updateRegister(string registerNum, string hex);
    //returns the registers
    string returnRegister(string regsiterNum);
    //prints out all the registers
    void printRegisters();
};