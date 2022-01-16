#include <iostream>
#include <vector>
#include "main.h"

//add function

int main(){

    //INVERT
    cout << "Normal Output: " << endl;
    myuint<4>OI(1 );      //<4> - No of bits || <5> Decimal to be converted
    myuint<4>T(4 );
    myuint<4>OS("2");
   // OS.displayVec();
    cout << endl;

    cout << "Addition: " << endl;
    myuint<4>A = OI + T;
    cout << endl;

    cout << "Shift Left: " << endl;
    myuint<4>L = (6);
    myuint<4>SL = L << 2;    //shift to the left by 1
    cout << endl;
    
    cout << "Shift Right: " << endl;
    myuint<4>R = (12);
    myuint<4>SR = R >> 2;
    cout << endl;

    cout << "Multiply: " << endl;
    myuint<8>M1(4);
    myuint<8>M2(3);
    myuint<8>M = M1 * M2;

    cout << "Check Equal: " << endl;
     myuint<4>E1(4);
     myuint<4>E2(4);
     myuint<4>E = E1 == E2;
    //?Checker to see if number given is too big for bits?
}


  