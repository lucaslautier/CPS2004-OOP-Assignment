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
    NODE<T>* tail_ = NULL;
    NODE<T>* itr = NULL;

public:

    acyclic()
    {
        this->n = 0;
    }

    acyclic(int[x],int s)
    {   
        for(int i = 0; i < s; i++){
            
        }
    }

    void addValue(T value)
    {
        if(this-> head == NULL)
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
                cout << "Value already exists, adding this will cause a cycle!" << endl;
            }   
        }
    }


};