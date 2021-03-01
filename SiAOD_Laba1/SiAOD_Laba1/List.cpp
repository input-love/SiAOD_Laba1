#include "List.h"

List::~List()
{
    if (_head != nullptr)
    {
        Node* currentElement = _head;
        for (int i = 0; i < _count - 1; i++)
        {
            currentElement = currentElement->_next;
            delete currentElement->_prev;
        }
        delete currentElement;
    }
}

void List::push_front(int data) {
    if (_head != nullptr)
    {
        _head = _head->_prev = new Node();
        _head->data = data;
    }
    else
    {
        create_first_node(data);
    }
    _count++;
}

void List::push_back(int data) {
    if (_tail != nullptr)
    {
        _tail = _tail->_next = new Node();
        _tail->data = data;
    }
    else
    {
        create_first_node(data);
    }
    _count++;
}

void List::pop_front()
{
    if (_head != nullptr && _count > 1)
    {
        _head = _head->_next;
        delete _head->_prev;
    }
    else if (_count)
    {
        delete _head;
    }
}

void List::pop_back()
{
    if (_tail != nullptr && _count > 1)
    {
        _tail = _tail->_prev;
        delete _tail->_next;
    }
    else if (_count)
    {
        delete _tail;
    }
}

const List::iterator& List::begin() const
{
    return iterator(_head);
}

const List::iterator& List::end() const
{
    return iterator(_tail);
}

void List::create_first_node(int data)
{
    _head = _tail = new Node();
    _head->data = data;
}

List::iterator::iterator(Node* node)
{
    _currentElement = node;
}

List::iterator::iterator(const iterator& itr) : _currentElement(itr._currentElement) {}

const List::iterator& List::iterator::operator=(const iterator& itr)
{
    if (this != &itr)
    {
        _currentElement = itr._currentElement;
        return *this;
    }
    return *this;
}

int List::iterator::operator*() const
{
    return _currentElement->data;
}

const List::iterator& List::iterator::operator++()
{
    _currentElement = _currentElement->_next;
    return *this;
}

const List::iterator& List::iterator::operator++(int)
{
    List::iterator temp = *this;
    _currentElement = _currentElement->_next;
    return temp;
}

const List::iterator& List::iterator::operator--()
{
    _currentElement = _currentElement->_prev;
    return *this;
}

const List::iterator& List::iterator::operator--(int)
{
    List::iterator temp = *this;
    _currentElement = _currentElement->_prev;
    return temp;
}

bool List::iterator::operator!=(const iterator& itr)
{
    return this == &itr;
}
