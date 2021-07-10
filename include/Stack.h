#include "LinkedList.h"
#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        void push(int data);
        int pop();
        int top();
        ~Stack();
        friend ostream& operator<<(ostream& os, Stack const& stack);
    private:
        LinkedList *stack; 
};



#endif