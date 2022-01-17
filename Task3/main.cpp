#include <iostream>
#include <vector>
#include "main.h"

//add function

int main(){

    //INVERT
    cout << " Output: " << endl;
    myuint<8>OI(10);      //<4> - No of bits || <5> Decimal to be converted
    myuint<8>T(3);
    myuint<4>OS("2");   //changes string to binary

    OI.displayVec();
    T.displayVec();
    OS.displayVec();
    cout << "-----------------" << endl;
    // cout << "Addition: " << endl;

    //just change operator to what you want
    myuint<8>A = OI % T;
    cout << endl;
    A.displayVec();

    //TEST CASES FOR BOOLEANS
    // if(OI > T){
    //     cout << "LHS larger";
    // }else{
    //     cout << "LHS smaller";
    // }
    // cout << endl;
    // if(OI != T){
    //     cout << "Not Equal";
    //  }
    //  else{
    //     cout << "Equal";
    //  }



    //A.displayVec();
    
    // cout << "Subtraction: "<< endl;
    // myuint<4>SUB1(4);
    // myuint<4>SUB2(16);
    // myuint<4>SUB = SUB1 - SUB2;
    // SUB.displayVec();
    // cout << endl;

    // cout << "Shift Left: " << endl;
    // myuint<4>L = (6);
    // myuint<4>SL = L << 2;    //shift to the left by 1
    // //SL.displayVec();
    // cout << endl;
    
    // cout << "Shift Right: " << endl;
    // myuint<4>R = (12);
    // myuint<4>SR = R >> 2;
    // SR.displayVec();
    // cout << endl;

    // cout << "Multiply: " << endl;
    // myuint<8>M1(4);
    // myuint<8>M2(3);
    // myuint<8>M = M1 * M2;
    // M.displayVec();

    // cout << "Check Equal: " << endl;
    //  myuint<4>E1(4);
    //  myuint<4>E2(4);
    //  if(E1 == E2){
    //     cout << "Equal";
    //  }
    //  else{
    //     cout << "Not Equal";
    //  }

     
    //?Checker to see if number given is too big for bits?
}


  