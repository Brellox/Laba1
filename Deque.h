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
    Deque(Node* head, Node*tail);
private:
    Node* head;
    Node* tail;
};

#endif
