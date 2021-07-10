#include "LinkedList.h"
#ifndef Queue_H
#define Queue_H


class Queue
{
    public:
        Queue();
        void enqueue(int data);
        int dequeue();
        int top();
        ~Queue();
        friend ostream& operator<<(ostream& os, Queue const& Queue);
    private:
        LinkedList *queue; 
};



#endif