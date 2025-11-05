#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class BTreeNode {
public:
  std::vector<T> keys;
  std::vector<BTreeNode<T>*> children;
  bool isLeaf;
  int minDegree;

  BTreeNode(int t, bool leaf) : minDegree(t), isLeaf(leaf) {}
};

template <typename T>
class BTree {
protected:
  BTreeNode<T>* root;
  int minDegree;

  // Métodos auxiliares recursivos/internos
  BTreeNode<T>* searchRec(BTreeNode<T>* node, T key) {
    // TODO: buscar key en el subárbol con raíz node
    return nullptr;
  }

  void splitChild(BTreeNode<T>* parent, int index) {
    // TODO: dividir el hijo lleno en parent->children[index]
    return;
  }

  void insertNonFull(BTreeNode<T>* node, T key) {
    // TODO: insertar en un nodo que no está lleno
    return;
  }

  void merge(BTreeNode<T>* node, int index) {
    // TODO: fusionar children[index] con children[index+1]
    return;
  }

  void borrowFromPrev(BTreeNode<T>* node, int index) {
    // TODO: tomar una key del hijo anterior
    return;
  }

  void borrowFromNext(BTreeNode<T>* node, int index) {
    // TODO: tomar una key del hijo siguiente
    return;
  }

  void fill(BTreeNode<T>* node, int index) {
    // TODO: llenar children[index] si tiene menos de t-1 keys
    return;
  }

  T getPredecessor(BTreeNode<T>* node, int index) {
    // TODO: obtener predecesor de keys[index]
    return T();
  }

  T getSuccessor(BTreeNode<T>* node, int index) {
    // TODO: obtener sucesor de keys[index]
    return T();
  }

  void removeFromLeaf(BTreeNode<T>* node, int index) {
    // TODO: eliminar keys[index] de un nodo hoja
    return;
  }

  void removeFromNonLeaf(BTreeNode<T>* node, int index) {
    // TODO: eliminar keys[index] de un nodo interno
    return;
  }

  void removeRec(BTreeNode<T>* node, T key) {
    // TODO: eliminar recursivamente
    return;
  }

  void traverseRec(BTreeNode<T>* node) {
    // TODO: recorrer e imprimir el árbol
    return;
  }

  void clearRec(BTreeNode<T>* node) {
    if(node == nullptr) return;
    
    for(auto child : node->children)
      clearRec(child);
    
    delete node;
  }

public:
  BTree(int t) : minDegree(t), root(nullptr) {}

  ~BTree() {
    clear();
  }

  void insert(T key) {
    // TODO: insertar key
    // Si root está lleno, crear nueva raíz y hacer split
    return;
  }

  bool search(T key) {
    return searchRec(root, key) != nullptr;
  }

  void remove(T key) {
    if(root == nullptr) {
      throw std::runtime_error("El árbol está vacío");
    }
    removeRec(root, key);
    
    // Si root queda vacío después de remove, bajar nivel
    if(root->keys.empty()) {
      BTreeNode<T>* tmp = root;
      root = root->isLeaf ? nullptr : root->children[0];
      delete tmp;
    }
    return;
  }

  void traverse() {
    if(root != nullptr)
      traverseRec(root);
    std::cout << std::endl;
  }

  void clear() {
    clearRec(root);
    root = nullptr;
  }
};