#include "BTNode.h"
#include <iostream>

#ifndef BST_H
#define BST_H

class BST
{
    public:
        BST(){ root = 0; }
        void insert(int data);
        bool isEmpty(){ return root == 0; }
        void remove(int val);
        void breadthFirstTraversal();
        void preOrderTraversal(BTNode* node);
        void inOrderTraversal(BTNode* node = 0);
        void postOrderTraversal(BTNode* node);
        void visit(BTNode *node){ std::cout << node -> data << " "; }
        bool isLeaf(BTNode *node){ return node -> left == 0 && node -> right == 0; }
        bool hasOneChild(BTNode *node){ return (node -> left != 0 || node -> right != 00) && (node -> left == 0 || node -> right == 0); }
        void swap(BTNode *nodeA, BTNode *nodeB);
        BTNode *search(int val);
        BTNode *getPredecessor(BTNode* node);
        BTNode *getsuccessor(BTNode* node);
        BTNode *findMin(BTNode* node);
        BTNode *findMax(BTNode* node);
        BTNode *findParent(BTNode *child);
    private:
        BTNode *root;
};

#endif