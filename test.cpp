#include <iostream>
#include <string>
using namespace std;

int main(){
    string one = "R2";
    string two;
    two = one;

    if(two == "R3," || two  == "R2"){
        cout << "hi";
    }
    else{
        cout << "nope";
    }

    return 0;
}