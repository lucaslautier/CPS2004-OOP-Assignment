#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#include <type_traits>
static_assert(03301 == 1729);

template <int T>
class myuint{
    private:
    std::vector<bool> bin;

    public:
    int sizeBits = T;
    bool isArbitrary;
    myuint(){
        
    }

    //to output
    void displayVec(){
        for(bool j:bin)
            std::cout << j;

        cout << endl;
    }
    
    //to convert to int
    void convert_to(){
        int decValue = 0;
        int power = sizeBits-1;

        for(bool j:bin){
            if(j == true){
                decValue = decValue + pow(2,power);
            }
            power--;
        }
        cout << decValue <<endl;

    }


    //Function to make an integer(decimal) -> binary
    myuint(int num){
        this->sizeBits = sizeBits;
        
        isArbitrary = arbitraryLen(sizeBits);
        
        
        assert(("The number is not a power of 2",isArbitrary == true ));
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
        
    }

    bool arbitraryLen(int size){
        if(size == 0){
            return false;
        }
        while(size != 1){
            if(size%2 != 0){
                return false;
            }
            size = size/2;
        }
        return true;
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
        isArbitrary = arbitraryLen(sizeBits);
        
        
        assert(("The number is not a power of 2",isArbitrary == true ));


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

       
    }

    //start overloading operators
    myuint operator + (const myuint& num)
    {
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        int carry = 0;
        //bin.size()
        //read it reverse to start from RHS
        for(int i =sizeBits -1; i >= 0; --i){
           
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

        for(int j= tmp.bin.size();j<sizeBits;j++){
            tmp.bin.push_back(0);
        }

        // for(bool j:tmp.bin)
        //     std::cout << j;

        cout << endl;
        //reverse back
        reverse(tmp.bin.begin(), tmp.bin.end());    

        return tmp;
    }

    myuint operator - (const myuint& num)
    {
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        
        int cnt = 0;
        for(int i = sizeBits-1 ; i > 0; i--){
            
            
            if(LHS.bin[i] - num.bin[i] == 0){
                tmp.bin.push_back(0);
                
            }
            else if(LHS.bin[i] - num.bin[i] == 1){
                tmp.bin.push_back(1);
                
            }
            else if(LHS.bin[i] - num.bin[i]  == -1){            
                tmp.bin.push_back(1);
                cnt = i - 1;
                for(cnt ; cnt >= 0; cnt--){
                   
                    if(LHS.bin[cnt] == 0){
                        LHS.bin[cnt] = 1;
                    }
                    else{
                        LHS.bin[cnt] = 0;
                        break;
                    }
                }
                
                
            }
            //cout << i;
        }
        for(int j= tmp.bin.size();j<sizeBits;j++){
            tmp.bin.push_back(0);
        }
        cout << endl;
        reverse(tmp.bin.begin(), tmp.bin.end());
        return tmp;
    }

    
    myuint operator >> (int num){
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        this->sizeBits = sizeBits;
        
       //push in new 0s to tmp
        for(int j = 0; j < num; j++){
            tmp.bin.push_back(0);
        }
        

        //push in original binary to tmp
        for(int i = 0; i < sizeBits; i++){
            tmp.bin.push_back(LHS.bin[i]);
        }
        
        
        for(int x = tmp.bin.size(); x > sizeBits; --x){
            tmp.bin.pop_back();
        }

        cout << endl;

        return tmp;
    }

    myuint operator << (int num){
        myuint<T> LHS = *this;
        myuint<T> tmp ;
        this->sizeBits = sizeBits;
        int i = 0;
        
        for(i = 0; i < sizeBits ; i++){
            tmp.bin.push_back(LHS.bin[i]);
        }
        
        for(int j = 0; j < num; j++){
            tmp.bin.push_back(0);
        }
  
        //reverse so that digits to be popped are at the back
        reverse(tmp.bin.begin(), tmp.bin.end());
       
        for(int x = tmp.bin.size(); x > sizeBits; --x){
            tmp.bin.pop_back();
        }

        //reverse back to original
        reverse(tmp.bin.begin(), tmp.bin.end());
        
        return tmp;
    }

    myuint operator * (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp;
        myuint<T> tmp2;
    
        myuint<T> toAdd;
        int cntA = 0;
        int cntB = 0;
        int counter = 1;
        int toShift = 1;
        int j = 0;

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
            for(j = 0; j < sizeBits ; j++)
            {
                if(1 * LHS.bin[j] == 1){
                    tmp.bin.push_back(1);
                }
                else{
                    tmp.bin.push_back(0);
                }
            }
        }
        //fill with 0s if one of them is all 0s (n * 0 = 0)
        else{
            for(int i = 0;i<sizeBits ; i++)
            {
               tmp.bin.push_back(0);
               return tmp;
            }
        }


        //copy into another vector so that they can be added
        // for(int i = 0; i < sizeBits ; i++){
        for(int i = 0 ; i < sizeBits; i++){
            toAdd.bin.push_back(tmp.bin[i]);
        }
        

        //with every add, the binary being added has to be shifted left
        //while loop to cntB (holds amnt. of 1s therefore times an addition needs to happen)
        while (counter < cntB){ 
            
            tmp2 = toAdd << 1;
            tmp = tmp + tmp2;
            
            counter++;
        }
      
        return tmp;
    }


    bool operator == (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        // myuint<T> tmp ;
        bool isEqual = true;

        for(int i = 0; i < sizeBits ; i++){
            if(LHS.bin[i] != num.bin[i]){
                return false;
            }
        }

        return true;
    }

    bool operator != (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        // myuint<T> tmp ;
        bool isEqual = false;

        for(int i = 0; i < sizeBits ; i++){
            if(LHS.bin[i] != num.bin[i]){
                return true;
            }
        }

        return false;
    }

    
    bool operator > (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        int pos1 = 0;
        int pos2 = 0;

        for(int i = 0; i < sizeBits; i++){
            if(LHS.bin[i] == 1){
                pos1 = i;
                //cout << pos1;
                break;
            }
        }
        for(int i = 0; i < sizeBits; i++){
            if(num.bin[i] == 1){
                pos2 = i;
                //cout << pos2;
                break;
            }
        }
        //smaller index, larger number (most left-most)
        if(pos1<pos2){
            return true;
        }

        return false;
    }

    int operator / (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp;
     
        int cnt = 0;

        while((LHS > num) == true){
            LHS = LHS - num;
          
            cnt++;
        }
        if(LHS == num){
            cnt+= 1;
            cout << cnt;
            return cnt;
        }
        else{
            cout << cnt;
        }
        

        return cnt;
    }

    myuint operator % (const myuint& num){
        this->sizeBits = sizeBits;
        myuint<T> LHS = *this;
        myuint<T> tmp;
        
        int rem = 0;
        while((LHS > num) == true){
            LHS = LHS - num;
        }

        if(LHS == num){
            LHS = LHS - num;
            return LHS;
        }
        
        return LHS;
    }

};

