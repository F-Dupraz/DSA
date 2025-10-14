#include "LinkedList.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

int main() {
  std::cout << "///  Stack opertions: " << std::endl;
  std::cout << std::endl;

  Stack<int>* myStack = new Stack<int>;

  myStack->push(30);
  myStack->push(20);
  myStack->push(30);
  myStack->push(40);
  myStack->push(30);

  myStack->print();

  std::cout << "head: " << myStack->getHead()->data << std::endl;
  std::cout << "tail: " << myStack->getTail()->data << std::endl;
  std::cout << std::endl;

  myStack->removeDeep(30);

  myStack->print();

  std::cout << "head: " << myStack->getHead()->data << std::endl;
  std::cout << "tail: " << myStack->getTail()->data << std::endl;
  std::cout << std::endl;

  std::cout << "///  Queue opertions: " << std::endl;
  std::cout << std::endl;

  Queue<int>* myQueue = new Queue<int>;

  myQueue->enqueue(10);
  myQueue->enqueue(20);
  myQueue->enqueue(30);
  myQueue->enqueue(40);
  myQueue->enqueue(50);

  myQueue->print();

  std::cout << "head: " << myQueue->getHead()->data << std::endl;
  std::cout << "tail: " << myQueue->getTail()->data << std::endl;
  std::cout << std::endl;

  myQueue->segmenetedInvert(3);

  myQueue->print();

  std::cout << "head: " << myQueue->getHead()->data << std::endl;
  std::cout << "tail: " << myQueue->getTail()->data << std::endl;
  std::cout << std::endl;

  std::cout << "///  Binary Tree opertions: " << std::endl;
  std::cout << std::endl;

  BinaryTree<int>* myBinaryTree = new BinaryTree<int>;

  myBinaryTree->insert(30);
  myBinaryTree->insert(10);
  myBinaryTree->insert(20);
  myBinaryTree->insert(40);
  myBinaryTree->insert(35);
  myBinaryTree->insert(50);
  myBinaryTree->insert(5);
  myBinaryTree->insert(32);
  myBinaryTree->insert(38);
  myBinaryTree->insert(45);
  myBinaryTree->insert(51);

  myBinaryTree->print();

  std::cout << "root: " << myBinaryTree->getRoot()->data << std::endl;

  std::cout << "minimum: " << myBinaryTree->minimum() << std::endl;
  std::cout << "maximum: " << myBinaryTree->maximum() << std::endl;

  std::cout << "leaves:";
  myBinaryTree->showLeaves();
  
  std::cout << "value 5: ";
    myBinaryTree->search(5) ? std::cout << "is in btree" : std::cout << "is not in btree";
  std::cout << std::endl;

  std::cout << "la altura del arbol es: " << myBinaryTree->getHeight() << std::endl;

  myBinaryTree->remove(40);

  myBinaryTree->print();

  std::cout << "la altura del arbol es: " << myBinaryTree->getHeight() << std::endl;

  std::cout << std::endl;

  return 0;
}