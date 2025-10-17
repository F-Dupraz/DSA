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
      if(tempLeft != nullptr) {
        BNode<T>* balancedLeft = this->insertRec(tempLeft, tempRight);
        return balancedLeft;
      }
      else {
        BNode<T>* balancedRight = this->insertRec(tempRight, tempLeft);
        return balancedRight;
      }
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

  bool isBalancedRec(BNode<T>* node) {
    if(node == nullptr) return true;

    if(this->getHeightRec(node->right) - this->getHeightRec(node->left) <= 1 &&
       this->getHeightRec(node->right) - this->getHeightRec(node->left) >= -1) {
        return isBalancedRec(node->right) && isBalancedRec(node->left);
      }

    return false;
  }

  void leftRotate(BNode<T>* node, BNode<T>* father) {
    BNode<T>* nRight = node->right;
    node->right = nRight->left;
    nRight->left = node;
    std::cout << "Cambiando " << node->data << " por " << nRight->data << std::endl;
    if(father == nullptr) this->root = nRight;
    else if(father->left == node) father->left = nRight;
    else father->right = nRight;
  }

  void rightRotate(BNode<T>* node, BNode<T>* father) {
    BNode<T>* nLeft = node->left;
    node->left = nLeft->right;
    nLeft->right = node;
    std::cout << "Cambiando " << node->data << " por " << nLeft->data << std::endl;
    if(father == nullptr) this->root = nLeft;
    else if(father->left == node) father->left = nLeft;
    else father->right = nLeft;
  }

  void balanceRec(BNode<T>* node, BNode<T>* father = nullptr) {
    if(node == nullptr) return;
    if(node->left == nullptr && node->right == nullptr) return;

    int hl = 0, hr = 0;

    if(node->left != nullptr) {
      balanceRec(node->left, node);
      hl = this->getHeightRec(node->left);
    }
    
    if(node->right != nullptr) {
      balanceRec(node->right, node);
      hr = this->getHeightRec(node->right);
    }

    int dif = hl - hr;

    if(dif < -1) {
      int rightBalance = getHeightRec(node->right->left) - getHeightRec(node->right->right);
      if(rightBalance > 0) {
        rightRotate(node->right, node);
      }
      leftRotate(node, father);
    } else if(dif > 1) {
      int leftBalance = getHeightRec(node->left->left) - getHeightRec(node->left->right);
      if(leftBalance < 0) {
        leftRotate(node->left, node);
      }
      rightRotate(node, father);
    }

    return;
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

  bool isBalanced() {
    return isBalancedRec(this->root);
  }

  void balance() {
    balanceRec(this->root);
    return;
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
