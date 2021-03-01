#pragma once

class List {
private:
    struct Node;
public:
    List() = default;
    ~List();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
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
        const iterator& operator--();
        const iterator& operator--(int);
        bool operator!=(const iterator& itr);
    private:
        friend class List;
        Node* _currentElement = nullptr;
    };
    iterator begin();
    iterator end();
private:
    void create_first_node(int data);
    struct Node {
        int data;
        Node* _next = nullptr;
        Node* _prev = nullptr;
    };
    int _count = 0;
    Node* _head = new Node();
    Node* _tail = _head;
};