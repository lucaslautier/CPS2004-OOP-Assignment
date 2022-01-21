#include <iostream>
#include <vector>
#include "main.h"

//add function

int main(){

    //INVERT
    cout << " Output: " << endl;
    myuint<8>OI(10);      //<4> - No of bits || <5> Decimal to be converted
    myuint<8>T(3);
    myuint<8>A = OI + T;
    A.convert_to();


    myuint<8>OS("2");   //changes string to binary

    T.displayVec();
    OS.displayVec();
    cout << "-----------------" << endl;
    // cout << "Addition: " << endl;

    //just change operator to what you want
    
    cout << endl;
    A.displayVec();
    
}


  