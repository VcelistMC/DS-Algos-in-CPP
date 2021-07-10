#ifndef BTNODE_H
#define BTNODE_H
#include <iostream>
class BTNode
{
    public:
        int data;
        BTNode *left, *right;
        BTNode(int data = 0, BTNode *left = 0, BTNode *right = 0)
        {
            this -> data = data;
            this -> left = left;
            this -> right = right;
        }
        bool operator==(BTNode that){ return (this -> data == that.data); }
        bool operator>(BTNode const that){ return this -> data > that.data; }
        bool operator<(BTNode const that){ return this -> data < that.data; }
};

#endif