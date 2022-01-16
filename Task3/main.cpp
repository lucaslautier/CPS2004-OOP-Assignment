#include <iostream>
#include <vector>
#include "main.h"

//add function

int main(){

    //INVERT
    cout << "Normal Output: " << endl;
    myuint<4>OI(1 );      //<4> - No of bits || <5> Decimal to be converted
    myuint<4>T(5 );
    myuint<4>OS("2"); 
    cout << endl;

    cout << "Addition: " << endl;
    myuint<4>A  = OI + T;
    cout << endl;

    cout << "Shift Left: " << endl;
    myuint<4>L = (6);
    myuint<4>SL = L << 2;    //shift to the left by 1
    cout << endl;
    
    cout << "Shift Right: " << endl;
    myuint<4>R = (12);
    myuint<4>SR = R >> 2;
    
    cout << "Multiply: " << endl;
    myuint<4>M1(4);
    myuint<4>M2(3);
    //myuint<8>M = M1 * M2;
    
    //?Checker to see if number given is too big for bits?
}

