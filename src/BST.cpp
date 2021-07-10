#include "BST.h"
#include <queue>
#include <iostream>
using namespace std;

void BST::insert(int data)
{
    if(root == 0)
    {
        root = new BTNode(data);
        return;
    }
    BTNode *curr = root;
    while(true)
    {
        if(data < curr -> data)
        {
            if(curr -> left == 0)
            {
                curr -> left = new BTNode(data);
                break;
            }
            else
                curr = curr -> left;
        }
        else
        {
            if(curr -> right == 0)
            {
                curr -> right = new BTNode(data);
                break;
            }
            else
                curr = curr -> right;
        }
    }
}

void BST::breadthFirstTraversal()
{
    queue<BTNode*> q;
    BTNode *curr = root;
    if(curr != 0)
    {
        q.push(curr);
        while (q.size() != 0)
        {
            curr = q.front();
            q.pop();
            visit(curr);
            if(curr -> left != 0)
                q.push(curr -> left);
            if(curr -> right != 0)
                q.push(curr -> right);
        }
    }
}

void BST::preOrderTraversal(BTNode* node)
{
    if(node==0)
        return;
    visit(node);
    preOrderTraversal(node -> left);
    preOrderTraversal(node -> right);
}

void BST::inOrderTraversal(BTNode* node)
{
    node = node == 0? root : node;
    if(node -> left != 0)
        inOrderTraversal(node -> left);
    visit(node);
    if(node -> right != 0)
        inOrderTraversal(node -> right);
}

void BST::postOrderTraversal(BTNode* node)
{
    if(node == 0)
        return;
    postOrderTraversal(node -> left);
    postOrderTraversal(node -> right);
    visit(node);
}

BTNode *BST::search(int val)
{
    BTNode *curr = root;
    while(curr != 0)
    {
        if(val == curr -> data)
            return curr;
        else if(val < curr -> data)
            curr = curr -> left;
        else
            curr = curr -> right;
    }
    return 0;
}

BTNode *BST::findMin(BTNode* node)
{
    if(node == 0)
        return 0;
    while(node -> left != 0)
        node = node -> left;
    return node;
}

BTNode *BST::findMax(BTNode* node)
{
    if(node == 0)
        return 0;
    while(node -> right != 0)
        node = node -> right;
    return node;
}

BTNode *BST::getsuccessor(BTNode* node)
{
    if(node -> right != 0)
        return findMin(node -> right);
    
    BTNode *succ = 0, *curr = root;
    while(root != 0)
    {
        if(node -> data < curr -> data)
        {
            succ = curr;
            curr = curr -> left;
        }
        else if(node -> data > curr -> data)
            curr = curr -> right;
        else
            break;
    }
    return succ;
}

BTNode *BST::getPredecessor(BTNode *node)
{
    if(node -> left != 0)
        return findMax(node -> left);

    BTNode *pred = 0, *curr = root;
    while(root != 0)
    {
        if(node -> data > curr -> data)
        {
            pred = curr;
            curr = curr -> right;
        }
        else if(node -> data < curr -> data)
            curr = curr -> left;
        else
            break;
    }
    return pred;
}

void BST::remove(int val)
{
    BTNode *node = search(val);
    if(node != 0)
    {
        if(isLeaf(node))
            delete node;
    }
}

BTNode *BST::findParent(BTNode *child)
{
    BTNode *parent = root;
    
}

void BST::swap(BTNode *nodeA, BTNode *nodeB)
{
    int temp = nodeA -> data;
    nodeA -> data = nodeB -> data;
    nodeB -> data = temp;
}