#include <iostream>
using namespace std;
#include "acyclic.h"
#include <string>

int main(){
    cout << "GRAPH USING INT";

    int x[]= { 1,2,4,5};
    int s = sizeof(x)/sizeof(x[0]);
    acyclic<int> M(x,s);
    M.print();
    M.remNode(3);
    M.print();

    cout << "-------------------------" << endl;
    cout << "GRAPH USING STRINGS" << endl;

    string x2[] = {"a","b","d","f"};
    int s2 = sizeof(x2)/sizeof(x2[0]);
    acyclic<string>M2(x2,s2);
    M2.print();
    //M2.remNode("c");
    M2.print();
    
}