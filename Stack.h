#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#include <ostream>

#include "Node.h"

template <typename T>
class Stack {
    Node<T> *topNode;
public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (topNode != nullptr) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->setPrevNode(topNode);
        topNode = newNode;
    }

    T pop() {
        if (topNode == nullptr) {
            std::cout << "Stos jest pusty" << std::endl;
            return T();
        }
        Node<T>* nodeToRemove = topNode;
        T valueToReturn = nodeToRemove->getValue();
        topNode = topNode->getPrevNode();
        delete nodeToRemove;
        return valueToReturn;
    }

    T peek() {
        if (topNode == nullptr) {
            std::cout << "Stos jest pusty" << std::endl;
            return T();
        }
        else {
            return topNode->getValue();
        }
    }

    Node<T>* getTopNode() {
        return topNode;
    }

    void setTopNode(Node<T> *newTopNode) {
        topNode = newTopNode;
    }
};

#endif //STACK_STACK_H
