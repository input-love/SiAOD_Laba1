#include "List.h"

List::~List()
{
    if (!_head)
    {
        Node* currentElement = _head;
        for (int i = 0; i < _count; i++)
        {
            currentElement = currentElement->_next;
            delete currentElement->_prev;
        }
        delete currentElement;
    }
}

void List::push_front(int data) {
    if (!_count)
    {
        create_first_node(data);
    }
    else
    {
        _head->_prev = new Node();
        _head->_prev->_next = _head;
        _head = _head->_prev;
        _head->data = data;
    }
    _count++;
}

void List::push_back(int data) {
    if (!_count)
    {
        create_first_node(data);
    }
    else
    {
        _tail->_next->_prev = _tail;
        _tail = _tail->_next;
        _tail->data = data;
        _tail->_next = new Node();
    }
    _count++;
}

void List::pop_front()
{
    if (_count > 1)
    {
        _head = _head->_next;
        delete _head->_prev;
        _count--;
    }
    else if (_count)
    {
        _tail = _head = _head->_next;
        delete _head->_prev;
        _count--;
    }
}

void List::pop_back()
{
    if (_count > 1)
    {
        Node* temp = _tail->_next;
        _tail = _tail->_prev;
        delete _tail->_next;
        _tail->_next = temp;
        _count--;
    }
    else if (_count)
    {
        _tail = _head = _tail->_next;
        delete _tail->_prev;
        _count--;
    }
}

List::iterator List::begin()
{
    return iterator(_head);
}

List::iterator List::end()
{
    return iterator(_tail->_next);
}

void List::create_first_node(int data)
{
    _head->_next = new Node();
    _head->_next->_prev = _head;
    _head->data = data;
}

// Определение класса "iterator"

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
    return this->_currentElement != itr._currentElement;
}
