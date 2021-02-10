#include <iostream>
#include <string>
#include <climits>
#include "List.h"

struct Node {
    int value;
    Node *next;
    ~Node() { std::cout << "no com valor " << value << " liberado" << std::endl; }
};

List::List() {
    head = new Node;
    head->next = head;
    head->value = 77777777;
}

// Completar