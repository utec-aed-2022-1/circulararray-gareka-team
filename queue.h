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
      push_back(a);
    }

    void dequeue() {
      pop_front();
    }

    int size() {
      return size();
    }

    void empty() {
      clear();
    }

    T front() {
      return getFront();
    }

    T back() {
      return getBack();
    }
};