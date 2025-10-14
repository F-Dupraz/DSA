#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class BNode {
public:
  T data;
  BNode<T> *left;
  BNode<T> *right;

  BNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
protected:
  BNode<T> *root;

  // Mio
  BNode<T>* insertRec(BNode<T> *father, BNode<T>* newNode) {
    if(this->root == nullptr) {
      this->root = newNode;
      return newNode;
    }

    if(father == nullptr) {
      return newNode;
    }

    if(father->data > newNode->data)
      father->left = insertRec(father->left, newNode);
  
    if(father->data <= newNode->data)
      father->right = insertRec(father->right, newNode);

    return father;
  }

  int getHeightRec(BNode<T>* node) {
    if(node == nullptr) return 0;

    if(node->right == nullptr && node->left == nullptr) return 1;

    int h_right = 1 + getHeightRec(node->right);
    int h_left = 1 + getHeightRec(node->left);

    return (h_right < h_left) ? h_left : h_right;
  }

  BNode<T>* removeRec(BNode<T>* node, T value) {
    if(node == nullptr) throw std::runtime_error("El valor no esta en el btree.");
    if(node->data == value) {
      BNode<T>* tempLeft = node->left;
      BNode<T>* tempRight = node->right;
      delete node;
      this->insertRec(tempLeft, tempRight);
      return tempLeft;
    }

    if(node->data <= value)
      node->right = removeRec(node->right, value);
    
    else if(node->data > value)
      node->left = removeRec(node->left, value);
  
    return node;
  }

  bool searchRec(BNode<T>* node, T value) {
    if(node == nullptr) return false;

    if(node->data == value) return true;
    
    if(node->data <= value)
      return searchRec(node->right, value);
    
    return searchRec(node->left, value);
  }

  void showLeavesRec(BNode<T>* node) {
    if(node->right == nullptr && node->left == nullptr)
      std::cout << " " << node->data;

    if(node->right != nullptr)
      showLeavesRec(node->right);
    if(node->left != nullptr)
      showLeavesRec(node->left);
    
    return;
  }

  T minimumRec(BNode<T>* node) {
    if(node->left == nullptr) return node->data;

    else return minimumRec(node->left);
  }

  T maximumRec(BNode<T>* node) {
    if(node->right == nullptr) return node->data;

    else return maximumRec(node->right);
  }

  void printRec(BNode<T>* node, int level) {
    if(node == nullptr) return;

    printRec(node->right, level+1);

    for(int i = 0; i <= level; ++i) 
      std::cout << "   ";

    std::cout << node->data << std::endl;

    printRec(node->left, level+1);

    return;
  }

  void clearRec(BNode<T>* node) {
    if(node == nullptr) return;

    clearRec(node->left);
    clearRec(node->right);

    delete node;
  }

public:
  BinaryTree() : root(nullptr) {}
    
  virtual ~BinaryTree() {
    clear();
  }

  BNode<T>* getRoot() {
    return this->root;
  }

  // Mio
  void insert(T value) {
    BNode<T>* newNode = new BNode<T>(value);
    insertRec(this->root, newNode);
    return;
  }

  int getHeight() {
    return getHeightRec(this->root);
  }

  void remove(T value) {
    removeRec(this->root, value);
    return;
  }

  bool search(T value) {
    return searchRec(this->root, value);
  }

  void showLeaves() {
    showLeavesRec(this->root);
    std::cout << std::endl;
    return;
  }

  T minimum() {
    return minimumRec(this->root);
  }

  T maximum() {
    return maximumRec(this->root);
  }

  void print() {
    printRec(this->root, 0);
    std::cout << std::endl;
    return;
  }

  void clear() {
    clearRec(this->root);
    root = nullptr;
    return;
  }
};
