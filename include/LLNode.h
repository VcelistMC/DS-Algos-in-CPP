#ifndef LLNODE_H
#define LLNODE_H

class LLNode
{
    public:
        int data;
        LLNode *next, *prev;
        LLNode(int data) { this -> data = data; next = prev = 0; }
};

#endif