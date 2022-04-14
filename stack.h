#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
public:
    void push(T a) {
      this -> push_front(a);
    }

    void pop() {
      this -> pop_front();
    }

    int size() {
      return this -> size();
    }

    void empty() {
      this -> clear();
    }

    T top(){
      return this -> getFront();
    }

};