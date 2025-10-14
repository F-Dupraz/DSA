#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
protected:
  Node<T>* head; 
  Node<T>* tail;
  size_t size;

  // Mio nuevo
  Node<T>* segmentedInvertRec(Node<T> *n, Node<T> *prev = nullptr, int k = 0) {  
    if(k == 1) {
      head->next = n->next;
      if(head->next == nullptr)
        tail = head;
      n->next = prev;
      head = n;
      return n;
    }

    Node<T> *nextNode = n->next;

    n->next = prev;

    return segmentedInvertRec(nextNode, n, k-1);
  }

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    virtual ~LinkedList() {
        clear();
    }

    virtual void insertFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    virtual void insertBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    virtual T removeFront() {
        if (!head) throw std::runtime_error("Lista vacía");
        
        Node<T>* temp = head;
        T value = temp->data;
        head = head->next;
        
        if (!head) tail = nullptr;
        
        delete temp;
        size--;
        return value;
    }

    virtual T removeBack() {
        if (!head) throw std::runtime_error("Lista vacía");
        
        if (head == tail) {
            T value = head->data;
            delete head;
            head = tail = nullptr;
            size--;
            return value;
        }

        Node<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        
        T value = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
        return value;
    }

    T peekFront() const {
        if (!head) throw std::runtime_error("Lista vacía");
        return head->data;
    }

    T peekBack() const {
        if (!tail) throw std::runtime_error("Lista vacía");
        return tail->data;
    }

    bool isEmpty() const { return size == 0; }
    size_t getSize() const { return size; }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data;
            if (current->next) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node<T>* getHead() { return head; }
    const Node<T>* getHead() const { return head; }

    Node<T>* getTail() { return tail; }
    const Node<T>* getTail() const { return tail; }

    // Mio nuevo
    Node<T>* segmentedInvert(int k) {
      if(k <= 0) throw std::runtime_error("k tiene que ser mayor a cero");
      if(k == 1) throw std::runtime_error("No se puede 'invertir' un elemento");
      if(this->getSize() < k) throw std::runtime_error("La lista no tiene tantos elementos");
      if(this->isEmpty()) throw std::runtime_error("La lista esta vacia");
      
      return segmentedInvertRec(head, nullptr, k);
    }
};