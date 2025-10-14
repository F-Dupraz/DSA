#pragma once
#include "LinkedList.h"

template <typename T>
class Stack : public LinkedList<T> {
private:
  // Mio nuevo
  void removeDeepRec(const T value) {
    if(!this->isEmpty() && this->getHead()->data == value) {
      this->pop();
      removeDeepRec(value);
      return;
    }

    if(this->isEmpty()) {
      return;
    }

    T temp = this->pop();

    removeDeepRec(value);

    this->push(temp);

    return;
  }

public:
  void push(const T& value) {
    this->insertFront(value);
  }

  T pop() {
    return this->removeFront();
  }

  T top() const {
    return this->peekFront();
  }

  // Mio nuevo
  void removeDeep(T value) {
    this->removeDeepRec(value);
    return;
  }
};
