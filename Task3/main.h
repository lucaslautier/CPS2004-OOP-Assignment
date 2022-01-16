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

    //to output
    void displayVec(vector<bool> vec){
        for(bool j:vec )
            std::cout << j;

        cout << endl;
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
        //displayVec(bin);
        // for(bool j:bin)
        //     std::cout << j;

        // cout<<endl;
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

        displayVec(bin);
        // for(bool j:bin)
        //     std::cout << j;
        // //check if odd or even
        // cout << endl;
    }

    //start overloading operators
    myuint operator + (const myuint& num)
    {
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        int carry = 0;
        //bin.size()
        for(int i =sizeBits -1; i >= 0; --i){
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
        reverse(tmp.bin.begin(), tmp.bin.end());
        displayVec(tmp.bin);
        
        // for(bool j:tmp.bin)
        //     std::cout << j;

        return tmp;
    }

    
    myuint operator << (int num){
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        this->sizeBits = sizeBits;
        
       
        for(int j = 0; j < num; j++){
            tmp.bin.push_back(0);
        }

        for(int i = sizeBits -1; i >= 0 ; --i){
            tmp.bin.push_back(LHS.bin[i]);
        }

        //sanity check - shifted left before removing extra bits
        // for(bool j:tmp.bin){
        //     std::cout << j;
        // }
        // cout << endl;
        
        for(int x = tmp.bin.size(); x > sizeBits; --x){
            tmp.bin.pop_back();
        }

        reverse(tmp.bin.begin(), tmp.bin.end());

        for(bool j:tmp.bin){
            std::cout << j;
        }

        cout << endl;

        return tmp;
    }

    myuint operator >> (int num){
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        this->sizeBits = sizeBits;

        for(int j = 0; j < num; j++){
            tmp.bin.push_back(0);
        }

        for(int i = 0; i < sizeBits ; i++){
            tmp.bin.push_back(LHS.bin[i]);
        }

        //sanity check - shifted left before removing extra bits
        // for(bool j:tmp.bin){
        //     std::cout << j;
        // 
        // cout<<endl;

        for(int x = tmp.bin.size(); x > sizeBits; --x){
            tmp.bin.pop_back();
        }

        displayVec(tmp.bin);
        
        return tmp;
    }

    myuint operator * (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp;
        myuint<T> toAdd;
        int cntA = 0;
        int cntB = 0;
        int counter = 0;
        //checks if there are any "1"s in binary values
        for(int i = 0; i < sizeBits; i++){
            if(LHS.bin[i] == 1){
                cntA += 1; 
            }
        }

        for(int i = 0; i < sizeBits; i++){
            if(num.bin[i] == 1){
                cntB += 1;
            }
        }

        //if one of them is all "0", mult will be 0.
        if(cntA > 0 && cntB > 0){

            //do 1* all of the LHS (every 1 * LHS will get the same result), save in tmp
            for(int i = 0; i < sizeBits; i++)
            {
                if(1 * LHS.bin[i] == 1){
                    tmp.bin.push_back(1);
                }
                else{
                    tmp.bin.push_back(0);
                }
            }
        }
        else{
            for(int i = 0; i < sizeBits; i++)
            {
               bin.push_back(0);
            }
        }

        

        //copy into another vector so that they can be added
        for(int i = 0; i < sizeBits ; i++){
            toAdd.bin.push_back(tmp.bin[i]);
        }
        //sanity check
        // for(bool j:toAdd.bin){
        //     std::cout << j;
        // }

        //with every add, the binary being added has to be shifted left
        //while loop to cntB (holds amnt. of 1 therefore times an addition needs to happen)
        while (counter < cntB){ 
            toAdd << counter;
            tmp = tmp + toAdd;  
            counter++;
        }

        displayVec(tmp.bin);
      
        return tmp;
    }


    myuint operator == (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        // myuint<T> tmp ;
        bool isEqual = true;

        for(int i = 0; i < sizeBits ; i++){
            if(LHS.bin[i] != num.bin[i]){
                isEqual = false;
            }
        }

        if(isEqual){
            cout << "The binary values are equal";
        }
        else{
            cout << "The binary values are not equal";
        }
        return LHS;
    }

};
