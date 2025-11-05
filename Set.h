#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

#include "Sorting.h"

template <typename T>
class Set {
protected:
  std::vector<T> elements;

  int findInsertPosition(const T& value) const {
    int left = 0, right = elements.size();
    
    while(left < right) {
      int mid = left + (right - left) / 2;
      
      if(elements[mid] < value)
        left = mid + 1;
      else
        right = mid;
    }
    
    return left;
  }

public:
  Set() {}

  Set(const std::vector<T>& vec) {
    for(const auto& val : vec)
      insert(val);
  }

  bool insert(const T& value) {
    if(contains(value))
      return false;
    
    int pos = findInsertPosition(value);
    elements.insert(elements.begin() + pos, value);
    return true;
  }

  bool remove(const T& value) {
    int pos = BinarySearch(this->elements, value, this->elements.size());
    
    if(pos == -1)
      return false;
    
    elements.erase(elements.begin() + pos);
    return true;
  }

  bool contains(const T& value) const {
    return BinarySearch(this->elements, value, this->elements.size()) != -1;
  }

  bool isEmpty() const {
    return elements.empty();
  }

  size_t size() const {
    return elements.size();
  }

  void clear() {
    elements.clear();
  }

  Set<T> setUnion(const Set<T>& other) const {
    Set<T> result;
    size_t i = 0, j = 0;
    
    while(i < elements.size() && j < other.elements.size()) {
      if(elements[i] < other.elements[j]) {
        result.elements.push_back(elements[i]);
        i++;
      } else if(elements[i] > other.elements[j]) {
        result.elements.push_back(other.elements[j]);
        j++;
      } else {
        result.elements.push_back(elements[i]);
        i++;
        j++;
      }
    }
    
    while(i < elements.size()) {
      result.elements.push_back(elements[i]);
      i++;
    }
    
    while(j < other.elements.size()) {
      result.elements.push_back(other.elements[j]);
      j++;
    }
    
    return result;
  }

  Set<T> intersection(const Set<T>& other) const {
    Set<T> result;
    size_t i = 0, j = 0;
    
    while(i < elements.size() && j < other.elements.size()) {
      if(elements[i] < other.elements[j]) {
        i++;
      } else if(elements[i] > other.elements[j]) {
        j++;
      } else {
        result.elements.push_back(elements[i]);
        i++;
        j++;
      }
    }
    
    return result;
  }

  Set<T> difference(const Set<T>& other) const {
    Set<T> result;
    size_t i = 0, j = 0;
    
    while(i < elements.size() && j < other.elements.size()) {
      if(elements[i] < other.elements[j]) {
        result.elements.push_back(elements[i]);
        i++;
      } else if(elements[i] > other.elements[j]) {
        j++;
      } else {
        i++;
        j++;
      }
    }
    
    while(i < elements.size()) {
      result.elements.push_back(elements[i]);
      i++;
    }
    
    return result;
  }

  Set<T> symmetricDifference(const Set<T>& other) const {
    Set<T> result;
    size_t i = 0, j = 0;
    
    while(i < elements.size() && j < other.elements.size()) {
      if(elements[i] < other.elements[j]) {
        result.elements.push_back(elements[i]);
        i++;
      } else if(elements[i] > other.elements[j]) {
        result.elements.push_back(other.elements[j]);
        j++;
      } else {
        i++;
        j++;
      }
    }
    
    while(i < elements.size()) {
      result.elements.push_back(elements[i]);
      i++;
    }
    
    while(j < other.elements.size()) {
      result.elements.push_back(other.elements[j]);
      j++;
    }
    
    return result;
  }

  bool isSubset(const Set<T>& other) const {
    if(size() > other.size())
      return false;
    
    for(const auto& elem : elements) {
      if(!other.contains(elem))
        return false;
    }
    
    return true;
  }

  bool isSuperset(const Set<T>& other) const {
    return other.isSubset(*this);
  }

  bool isDisjoint(const Set<T>& other) const {
    size_t i = 0, j = 0;
    
    while(i < elements.size() && j < other.elements.size()) {
      if(elements[i] < other.elements[j]) {
        i++;
      } else if(elements[i] > other.elements[j]) {
        j++;
      } else {
        return false;
      }
    }
    
    return true;
  }

  const std::vector<T>& getElements() const {
    return elements;
  }

  T at(size_t index) const {
    if(index >= elements.size())
      throw std::runtime_error("Índice fuera de rango");
    return elements[index];
  }

  void print() const {
    std::cout << "{ ";
    for(size_t i = 0; i < elements.size(); ++i) {
      std::cout << elements[i];
      if(i < elements.size() - 1)
        std::cout << ", ";
    }
    std::cout << " }" << std::endl;
  }

  Set<T> operator+(const Set<T>& other) const {
    return setUnion(other);
  }

  Set<T> operator*(const Set<T>& other) const {
    return intersection(other);
  }

  Set<T> operator-(const Set<T>& other) const {
    return difference(other);
  }

  bool operator==(const Set<T>& other) const {
    return elements == other.elements;
  }

  bool operator!=(const Set<T>& other) const {
    return !(*this == other);
  }
};