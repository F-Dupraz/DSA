#pragma once
#include "LinkedList.h"

template <typename T>
class Queue : public LinkedList<T> {
  private:
  // Mio nuevo
  void accommodate(int q) {
    if(q == 0) return;

    T aux = this->dequeue();
    this->enqueue(aux);

    accommodate(q-1);

    return;
  }

  void segmentedInvertRec(int k) {
    if(k == 1) {
      T temp = this->dequeue(); 
      this->enqueue(temp);
      return;
    }

    T aux = this->dequeue();

    segmentedInvertRec(k-1);

    this->enqueue(aux);

    return;
  }
  
public:
  void enqueue(const T& value) {
    this->insertBack(value);
  }

  T dequeue() {
    return this->removeFront();
  }

  T front() const {
    return this->peekFront();
  }

  // Mio nuevo
  void segmenetedInvert(int k) {
    if(k <= 0) throw std::runtime_error("k tiene que ser mayor a cero");
    if(k == 1) throw std::runtime_error("No se puede 'invertir' un elemento");
    if(this->getSize() < k) throw std::runtime_error("La lista no tiene tantos elementos");
    if(this->isEmpty()) throw std::runtime_error("La lista esta vacia");

    segmentedInvertRec(k);
    accommodate(this->getSize() - k);

    return;
  }
};