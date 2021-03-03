#include "List.h"

List::~List()
{
    Node* currentElement = _head;
    for (int i = 0; i < _count; i++)
    {
        currentElement = currentElement->_next;
        delete currentElement->_prev;
    }
    delete _default_node;
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
        _head->_data = data;
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
        _tail->_next = new Node();
        _tail->_next->_prev = _tail;
        _tail = _tail->_next;
        _tail->_next = _default_node;
        _tail->_data = data;
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
        delete _head;
        _head = _default_node;
        _count--;
    }
}

void List::pop_back()
{
    if (_count > 1)
    {
        _tail = _tail->_prev;
        delete _tail->_next;
        _tail->_next = _default_node;
        _count--;
    }
    else if (_count)
    {
        delete _tail;
        _head = _default_node;
        _count--;
    }
}

void List::insert(const iterator& itr, int data)
{
    if (!_count)
    {
        create_first_node(data);
    }
    else if (itr == begin())
    {
        push_front(data);
    }
    else if (itr == end())
    {
        push_back(data);
    }
    else
    {
        Node* new_node = new Node();
        new_node->_data = data;
        new_node->_next = itr._currentElement;
        new_node->_prev = itr._currentElement->_prev;
        new_node->_prev->_next = new_node;
        itr._currentElement->_prev = new_node;
    }
    _count++;
}

void List::swap()
{
    if (_count > 2)
    {
        Node* temp_first = _head->_next;
        Node* temp_second = _tail->_prev;

        _head->_next = _default_node;
        _head->_prev = temp_second;

        _tail->_next = temp_first;
        _tail->_prev = nullptr;

        temp_first->_prev = _tail;
        temp_second->_next = _head;

        Node* temp_swap = _head;
        _head = _tail;
        _tail = temp_swap;
    }
    else if (_count == 2)
    {
        _head->_next = _default_node;
        _head->_prev = _tail;

        _tail->_next = _head;
        _tail->_prev = nullptr;

        _head = _tail;
        _tail = _tail->_next;
    }
}

List::iterator List::begin()
{
    return iterator(_head);
}

List::iterator List::end()
{
    return iterator(_default_node);
}

void List::create_first_node(int data)
{
    _head = new Node();
    _head->_next = _default_node;
    _head->_data = data;
    _tail = _head;
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
    return _currentElement->_data;
}

const List::iterator& List::iterator::operator++()
{
    if (_currentElement->_next)
    {
        _currentElement = _currentElement->_next;
        return *this;
    }
    else
    {
        throw std::exception("---Нельзя сделать смещение на такое расстояние!---");
    }
}

const List::iterator& List::iterator::operator++(int)
{
    if (_currentElement->_next)
    {
        List::iterator temp = *this;
        _currentElement = _currentElement->_next;
        return temp;
    }
    else
    {
        throw std::exception("---Нельзя сделать смещение на такое расстояние!---");
    }
}

bool List::iterator::operator==(const iterator& itr) const
{
    return this->_currentElement == itr._currentElement;
}

bool List::iterator::operator!=(const iterator& itr) const
{
    return this->_currentElement != itr._currentElement;
}
