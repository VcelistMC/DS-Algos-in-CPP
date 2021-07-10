#include "Queue.h"
#include "LinkedList.h"

Queue::Queue()
{
    queue = new LinkedList();
}

void Queue::enqueue(int data)
{
    queue -> push_back(data);
}

int Queue::dequeue()
{
    return queue -> pop_front();
}

int Queue::top()
{
    return queue -> top();
}

ostream& operator<<(ostream &os, Queue const& queue)
{
    os << *(queue.queue);
    return os;
}

Queue::~Queue(){
    delete queue;
}