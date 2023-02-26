// Implementation file for linked StackType
#include "Stack.h"

template<class T>
StackType<T>::StackType() {
    topPtr = nullptr;
}

template<class T>
StackType<T>::~StackType() {
    while (topPtr != nullptr) {
        Node * temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

template<class T>
bool StackType<T>::IsFull() const {
    try {
        Node * temp = new Node;
        delete temp;
    } catch (std::bad_alloc e) {
        return true;
    }
    return false;
}

template<class T>
bool StackType<T>::IsEmpty() const {
    return topPtr == nullptr;
}

template<class T>
void StackType<T>::Push(T item) {
    if (IsFull()) {
        throw FullStack();
    }

    Node * nodeToInsert = new Node;
    nodeToInsert->info = item;
    nodeToInsert->next = topPtr;
    topPtr = nodeToInsert;

}

template<class T>
void StackType<T>::Pop() {
    if (IsEmpty()) {
        throw EmptyStack();
    }
    Node * temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
}

template<class T>
T StackType<T>::Top() {
    if (IsEmpty()) {
        throw EmptyStack();
    }
    return topPtr->info;
}