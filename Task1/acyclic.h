#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    T value;
    Node *next;
    Node *prev;
    Node(T value){
        this -> value = value;
    }

    int branch = 0;
};

template <typename T>
class acyclic
{
private: 
    int n;
    Node<T>* head_ = NULL;
    Node<T>* tail_ = NULL;
    

public:

    acyclic()
    {
        this->n = 0;
    }

    acyclic(int x[],int s)
    {   
        for(int i = 0; i < s; i++){
            addValue(x[i]);
        }
    }

    void addValue(T value)
    {
        if(this-> head_ == NULL)
        {
            this->head_ = new Node<T>(value);
            this->tail_ = this->head_;
            this->n += 1;
        }
        else
        {
            int chk = check(value);
            if (chk > 0)
            {
                if(chk == 2){
                    this->tail_->branch = 1;
                }

                this->tail_->next = new Node<T>(value);     
                this->tail_->next->prev = this->tail_;      
                this->tail_ = this->tail_->next;
                this->tail_->next = NULL;              
                this->n += 1;   
            }
            else
            {
                cout << "Value '"<< value << "' already exists, adding this will cause a cycle!" << endl;
            }   
        }
    }

    int check(T val)
    {
        int count = 0;
        Node<T>* x = this-> head_;

        for(int i = 0; i < n; i++)
        {         //go through all the list
            if(x->value == val)             //if node trying to be added is repeated, skip
            {
                count++;
            }
            x=x->next;
        }
        if(count>1)
        {
            return 0;
        }
        else{
            if (count == 1)
            {
                return 2;
            }
            return 1;
        }
    }

    void remNode(T val){
        int flag = 0;
        int count = 0;
        Node<T>* x = this->head_;
        for(int i = 0; i<this->n;i++)
        {
            if(x->value == val)
            {
                if(i==this->n-1)
                {
                    x->value = x->prev->value;
                    x->prev = x->prev->prev;
                    this->n = this->n-1;
                    
                }
                else{
                    x->value = x ->next->value;
                    x->next = x->next->next;
                    this->n = this->n-1;
                }
                flag++;
            }
            x = x->next;
        }
        if (flag == 0){
            cout << endl << "Node '" << val << "' does not exist" <<endl <<endl;
        }
        else{
            cout << endl << "The node '" << val << "' has been successfully removed" << endl;
        }
    }
    //just for checking

    void print()
    {
        cout << endl;
        int count = 0;

        Node<T>* x = this-> head_;
        for(int i=0; i<this-> n; i++)
        {
            cout<< x->value;
            if(x->branch == 1)
            {
                cout << endl;
            }
            else{
                if(i!= this-> n - 1)
                {
                    cout <<"->";
                }
            }
            x = x-> next;
        }
        cout <<endl<<endl;
    }

};