#ifndef Deque_h
#define Deque_h
#include "Header.h"
struct Node
{
    Payment data;
    Node* next;
};

class Deque
{
public:
    Deque();
    Deque(Node* head, Node* tail);
    Deque(const Deque &t);
    ~Deque();
    void push_front(Payment data);
    void pop_front();
    void pop_back();
    
private:
    Node* head;
    Node* tail;
};

#endif
