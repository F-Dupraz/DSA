#include "LinkedList.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"
#include "Sorting.h"


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

  myBinaryTree->isBalanced() ? std::cout << "balanced" : std::cout << "not balanced";
  std::cout << std::endl;

  myBinaryTree->remove(40);

  myBinaryTree->print();

  std::cout << "la altura del arbol es: " << myBinaryTree->getHeight() << std::endl;

  bool isB = myBinaryTree->isBalanced();
  isB ? std::cout << "balanced" : std::cout << "not balanced";
  std::cout << std::endl;

  if(!isB) myBinaryTree->balance();
  myBinaryTree->print();

  std::cout << std::endl;

  std::cout << "///  Sorting opertions: " << std::endl;
  std::cout << std::endl;

  int arr1[100] = {
    42, 7, 91, 18, 63, 27, 84, 12, 56, 2,
    33, 68, 45, 74, 10, 29, 51, 87, 5, 98,
    36, 23, 71, 59, 49, 81, 25, 15, 39, 94,
    70, 8, 99, 31, 64, 21, 47, 13, 62, 3,
    58, 92, 16, 73, 11, 77, 32, 67, 48, 20,
    80, 9, 26, 53, 66, 40, 14, 93, 22, 54,
    46, 97, 60, 37, 85, 19, 79, 4, 75, 43,
    30, 17, 86, 61, 28, 52, 34, 90, 6, 83,
    65, 1, 76, 24, 88, 55, 50, 41, 95, 38,
    82, 78, 35, 72, 44, 89, 96, 57, 69, 100
  };

  int arr2[100] = {
    42, 7, 91, 18, 63, 27, 84, 12, 56, 2,
    33, 68, 45, 74, 10, 29, 51, 87, 5, 98,
    36, 23, 71, 59, 49, 81, 25, 15, 39, 94,
    70, 8, 99, 31, 64, 21, 47, 13, 62, 3,
    58, 92, 16, 73, 11, 77, 32, 67, 48, 20,
    80, 9, 26, 53, 66, 40, 14, 93, 22, 54,
    46, 97, 60, 37, 85, 19, 79, 4, 75, 43,
    30, 17, 86, 61, 28, 52, 34, 90, 6, 83,
    65, 1, 76, 24, 88, 55, 50, 41, 95, 38,
    82, 78, 35, 72, 44, 89, 96, 57, 69, 100
  };

  int arr3[100] = {
    42, 7, 91, 18, 63, 27, 84, 12, 56, 2,
    33, 68, 45, 74, 10, 29, 51, 87, 5, 98,
    36, 23, 71, 59, 49, 81, 25, 15, 39, 94,
    70, 8, 99, 31, 64, 21, 47, 13, 62, 3,
    58, 92, 16, 73, 11, 77, 32, 67, 48, 20,
    80, 9, 26, 53, 66, 40, 14, 93, 22, 54,
    46, 97, 60, 37, 85, 19, 79, 4, 75, 43,
    30, 17, 86, 61, 28, 52, 34, 90, 6, 83,
    65, 1, 76, 24, 88, 55, 50, 41, 95, 38,
    82, 78, 35, 72, 44, 89, 96, 57, 69, 100
  };

  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j)
      std::cout << " " << arr1[(i*10)+j];
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << " InsertionSort: " << std::endl;

  InsertionSort(arr1, 100);

  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j)
      std::cout << " " << arr1[(i*10)+j];
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << " SelectionSort: " << std::endl;

  SelectionSort(arr2, 100);

  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j)
      std::cout << " " << arr2[(i*10)+j];
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << " BubbleSort: " << std::endl;

  BubbleSort(arr3, 100);

  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j)
      std::cout << " " << arr3[(i*10)+j];
    std::cout << std::endl;
  }

  int s = 1000;
  std::cout << std::endl;
  std::cout << "Looking for " << s << "...";
  BinarySearchRec(s, arr1, 100) ? std::cout << " found." << std::endl : std::cout << " not found." << std::endl;

  std::cout << std::endl;

  return 0;
}