#pragma once
#include <iostream>
using namespace std;

template <int T>

class myuint{
    public:
    int size = T;
    std::vector<bool> bin;

    //Function to make an integer(decimal) -> binary
    myuint(int num){
        this->size = size;
        int i = 0;

        //calculates if current bit gives 0 or 1, inputs into vec
        while(num!= 0){
            bin.push_back(num%2);
            num = num/2;
            i++;
        }
        //fills remaining bits with 0s(weren't filled as decimal was already found)
        for(i;i<size;i++){
            bin.push_back(0);
        }

        //test output
        for(bool j:bin)
            std::cout << j;
    }

    myuint(string s)
};
