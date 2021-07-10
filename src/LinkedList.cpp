#include "LinkedList.h"
#include "LLNode.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){ head = tail = 0;}

void LinkedList::push_back(int data)
{
    LLNode *newNode = new LLNode(data);
    if(isEmpty())
        head = tail = newNode;
    else
    {
        tail -> next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::push_front(int data)
{
    LLNode *newNode = new LLNode(data);
    if(isEmpty())
        head = tail = newNode;
    else
    {
        newNode -> next = head;
        head = newNode;
    }
    size++;
}

void LinkedList::insert(int pos, int data)
{
    if(pos >= size)
        throw runtime_error("out of bounds");
    else if(pos == 0)
        push_front(data);
    else if(pos == size - 1)
        push_back(data);

    LLNode *newNode = new LLNode(data);
    LLNode *curr = head;
    for(int i = 0; i < pos-1; i++)
        curr = curr -> next;
    
    newNode -> next = curr -> next;
    curr -> next = newNode;
    size++;
}

int LinkedList::pop_front()
{
    if(isEmpty())
        throw runtime_error("List is empty");

    int out = head -> data;
    LLNode *deletedNode = head;
    head = head -> next;
    delete deletedNode;
    size--;

    return out;
}

int LinkedList::pop_back()
{
    if(isEmpty())
        throw runtime_error("List is empty");

    int out = tail -> data;
    LLNode *curr = head;
    while(curr -> next != tail)
        curr = curr -> next;
    delete tail;
    tail = curr;
    size--;

    return out;
}

int LinkedList::pop(int pos)
{
    if(pos >= size)
        throw runtime_error("out of bounds");
    else if(pos == 0)
        return pop_front();
    else if(pos == size - 1)
        return pop_back();

    LLNode *curr = head;
    for(int i = 0; i < pos-1; i++)
        curr = curr -> next;
    LLNode *deletedNode = curr -> next;
    curr -> next = curr -> next -> next;
    int out = deletedNode -> data;
    delete deletedNode;
    size--;

    return out;
}

int LinkedList::top()
{
    return head -> data;
}

int LinkedList::bottom()
{
    return tail -> data;
}

ostream& operator<<(ostream& os, LinkedList const& list)
{
    int n = list.size;
    LLNode *curr = list.head;
    for(int i = 0; i < n; i ++)
       { os << curr -> data << " "; curr = curr -> next; }
    os << endl;
    return os;
}

int LinkedList::operator[](int pos)
{
    if(pos >= size)
        throw runtime_error("out of bounds"); 
    LLNode *curr = head;
    for(int i = 0; i < pos; i ++)
        curr = curr -> next;
    return curr -> data;
}

LinkedList::~LinkedList()
{
    while(head != 0)
    {
        LLNode *deletedNode = head;
        head = head -> next;
        delete deletedNode;
    }
}

LinkedList::Iterator& LinkedList::Iterator::operator++()
{
    if(curr == 0)
        throw runtime_error("null iterator");

    curr = curr -> next;
    return *this;
}

LinkedList::Iterator& LinkedList::Iterator::operator++(int)
{
    if(curr == 0)
        throw runtime_error("null iterator");
    
    Iterator tmp = *this;
    curr = curr -> next;
    return tmp;
}

int LinkedList::Iterator::operator*()
{
    if(curr == 0)
        throw runtime_error("null iterator");
    
    return curr -> data;
}