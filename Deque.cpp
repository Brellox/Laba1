#include "Deque.h"

Deque::Deque()
{
    this->head = nullptr;
    this->tail = nullptr;
}

Deque::Deque(Node* head, Node* tail)
{
    this->head = head;
    this->tail = tail;
}

Deque::Deque(const Deque &t)
{
    this->head = t.head;
    this->tail = t.tail;
}

Deque::~Deque()
{
    while (this->head->next != nullptr)
    {
        this->pop_back();
    }
    delete this->head;
}

void Deque::push_front(Payment data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = this->head;
    this->head=tmp;
    delete tmp;
}

void Deque::pop_front()
{
    this->head = this->head->next;
}

void Deque::pop_back()
{
    Node *tmp = this->head;
    while (tmp->next != this->tail)
    {
        tmp = tmp->next;
    }
    this->tail = tmp;
    delete tmp;
}
