#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

template <int T>

class myuint{
    private:
    std::vector<bool> bin;

    public:
    int sizeBits = T;
    
    myuint(){
        
    }
    //Function to make an integer(decimal) -> binary
    myuint(int num){
        this->sizeBits = sizeBits;
        int i = 0;

        //calculates if current bit gives 0 or 1, inputs into vec
        while(num!= 0){
            bin.push_back(num%2);
            num = num/2;
            i++;
        }
        //fills remaining bits with 0s(weren't filled as decimal was already found)
        for(i;i<sizeBits;i++){
            bin.push_back(0);
        }

        reverse(bin.begin(), bin.end());
        //test output
        for(bool j:bin)
            std::cout << j;

        cout<<endl;
    }

    string divideString(string num){
        //code for that  here
        int divisor = 2;
        string ans;

        int idx = 0;
        int temp = num[idx] - '0';

        while(temp < divisor)
        {
            temp = temp*10 + (num[++idx] - '0');
        }
        while(num.size() > idx){
            ans += (temp/divisor) + '0';
            temp = (temp%divisor) *10 + num[++idx] -'0';
        }

        if(ans.length()==0){
            return "0";
        }

        return ans;
    }

    //switch current digit to ASCII, check if it is odd or even
    bool oddOrEven(int currNo){
        
        if(currNo % 2 == 0){
            return true;
        }else{
            return false;
        }
    }

    myuint(string s)
    {
     //code for that here
        this->sizeBits = sizeBits;  
        bool isEven = false;
        int size = s.size();  
        int i = 0;
        while(s != "0"){
            size = s.size();              //size of string
            
            int tmp = s[size-1] -'0';         //read last element in string
            isEven = oddOrEven(tmp);          //check if odd or even
        
            if(isEven){
                bin.push_back(0);             //if even-push 0
                i++;
            }else{
                bin.push_back(1);             //if odd - push 1
                i++;
            }

            s = divideString(s);

        }

        for(i;i<sizeBits;i++){
            bin.push_back(0);
        }
        reverse(bin.begin(), bin.end());

        for(bool j:bin)
            std::cout << j;
        //check if odd or even
        
    }

    myuint operator + (const myuint& num)
    {
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        int carry = 0;
        for(int i =bin.size() -1; i >= 0; --i){
            LHS.bin[i];
            num.bin[i];

            if(LHS.bin[i] + num.bin[i] + carry == 0){
                tmp.bin.push_back(0);
                carry = 0;
            }
            else if(LHS.bin[i] + num.bin[i] + carry == 1){
                tmp.bin.push_back(1);
                
                carry = 0;
            }
            else if(LHS.bin[i] + num.bin[i] + carry  == 2){
                tmp.bin.push_back(0);
                
                carry = 1;
            }
            else if(LHS.bin[i] + num.bin[i] + carry  == 3){
                tmp.bin.push_back(1);       
                carry = 1;
            }

            
        }

        int j = 0;
        
        for(j = tmp.bin.size()-1; j >= 0 ; --j){
            cout << tmp.bin[j];
            // cout << "test" ;
        }
            
        // cout << j;


        return tmp;
    }

    

};
