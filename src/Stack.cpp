#include "Stack.h"
#include "LinkedList.h"

Stack::Stack(){ stack = new LinkedList(); }

void Stack::push(int data)
{
    stack -> push_front(data);
}

int Stack::pop()
{
    return stack -> pop_front();
}

int Stack::top()
{
    return stack -> top();
}

ostream& operator<<(ostream &os, Stack const& stack)
{
    os << *(stack.stack);
    return os;
}

Stack::~Stack()
{
    delete stack;
}