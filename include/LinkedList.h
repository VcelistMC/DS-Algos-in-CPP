#include "LLNode.h"
#include <iostream>
using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class LinkedList
{
    public:
        LinkedList();
        
        class Iterator
        {
            public:
                Iterator(LLNode *node){ curr = node; }
                Iterator& operator++();
                Iterator& operator++(int);
                int operator*();
                ~Iterator(){curr = 0;}

            private:
                LLNode *curr;
        };

        void push_back(int data);
        void push_front(int data);
        void insert(int pos, int data);
        int pop_front();
        int pop_back();
        int pop(int pos);
        int top();
        int bottom();
        Iterator begin(){ return Iterator(head); }
        Iterator end(){ return Iterator(tail); }
        friend ostream& operator<<(ostream& os, LinkedList const& list);
        int operator[] (int pos);
        bool isEmpty() { return head == 0; }
        ~LinkedList();
    private:
        LLNode *head, *tail;
        int size = 0;
};

#endif