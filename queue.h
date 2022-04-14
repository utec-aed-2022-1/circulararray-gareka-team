#include "circulararray.h"

template <typename T>
class QueueArray : protected CircularArray<T> { 
  public:
    void enqueue(T data);
    void dequeue(); 
    int size();
    void empty();
    T front();
    T back();

    void enqueue(T a) {
      this -> push_back(a);
    }

    void dequeue() {
      this -> pop_front();
    }

    int size() {
      return this -> size();
    }

    void empty() {
      this -> clear();
    }

    T front() {
      return this -> getFront();
    }

    T back() {
      return this -> getBack();
    }
};