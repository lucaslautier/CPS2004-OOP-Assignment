#include <iostream>
using namespace std;
#include "acyclic.h"

int main(){
    int x[]= { 1,2,1,3,2,4};
    //int s = 6;
    int s = sizeof(x)/sizeof(x[0]);
    //cout << s;
    acyclic<int> M(x,s);
    M.print();
    M.remNode(4);
    M.print();
    
}