#include <iostream>
using namespace std;
#include "acyclic.h"

int main(){
    int x[]= { 1,2,4,5};
    int s = sizeof(x)/sizeof(x[0]);
    acyclic<int> M(x,s);

    M.print();
    M.remNode(3);
    M.print();
    
}