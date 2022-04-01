#include "circulararray.h"

template <typename T>
class QueueArray : protected CircularArray<T> { 
  public:
    void push(T a) {
      push_back(a);
    }

    void pop() {
      pop_front();
    }

    int size() {
      size();
    }

    void empty() {
      empty();
    }

    void front() {
      getFront();
    }

    void back() {
      getBack();
    }
};