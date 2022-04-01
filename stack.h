#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
public:
	void push(T data);
	void pop(); 
	int size();
	void empty();
    T top();
  
    void push(T a) {
      push_front(a);
    }

    void pop() {
      pop_front();
    }

    int size() {
      return size();
    }

    void empty() {
      clear();
    }

    T top(){
        return getFront();
    }

};