#pragma once
#include <iostream>

class List {
private:
    struct Node;
    class iterator;
public:
    List() = default;
    ~List();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
    void insert(const iterator& itr, int data);
    void swap();
    class iterator
    {
    public:
        iterator() = default;
        iterator(Node* node);
        iterator(const iterator& itr);
        ~iterator() = default;
        const iterator& operator=(const iterator& itr);
        int operator*() const;
        const iterator& operator++();
        const iterator& operator++(int);
        bool operator==(const iterator& itr) const;
        bool operator!=(const iterator& itr) const;
    private:
        friend class List;
        Node* _currentElement = nullptr;
    };
    iterator begin();
    iterator end();
private:
    void create_first_node(int data);
    struct Node {
        int _data;
        Node* _next = nullptr;
        Node* _prev = nullptr;
    };
    int _count = 0;
    Node* _default_node = new Node();
    Node* _head = _default_node;
    Node* _tail = nullptr;
};