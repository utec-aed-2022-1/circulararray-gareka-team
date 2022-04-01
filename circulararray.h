#include <iostream>

using namespace std;

template <class T>
class CircularArray {
private:
	T *array;
	int capacity;
	int back, front, lenght;

public:
	CircularArray();
	CircularArray(int _capacity);
	virtual ~CircularArray();
	void push_front(T data);
	void push_back(T data);
	void insert(T data, int pos);
	T pop_front();
	T pop_back();
	bool is_full();
	bool is_empty();
	int size();
	void clear();
	T &operator[](int);
	void sort();
	bool is_sorted();
	void reverse();
	string to_string(string sep = " ");

private:
	int next(int);
	int prev(int);
};


template <class T>
CircularArray<T>::CircularArray() {
	CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int capacity) {
	this->array = new T[capacity];
	this->capacity = capacity;
	this->front = this->back = -1;
	this->lenght = 0;
}

template <class T>
CircularArray<T>::~CircularArray() {
	delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index) {
	return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index) {
	return (index + 1) % capacity;
}

template <class T>
void CircularArray<T>::push_front(T data) {
	if(is_full()) {
		cout << "El arreglo está lleno" << endl;
		return;
	}

	if(is_empty()) 
		front = back = 0;
	else
		front = prev(front);
	
	array[front] = data;
	++lenght;
}

template <class T>
void CircularArray<T>::push_back(T data) {
	if(is_empty()) {
		push_front(data);
		return;
	}
	
	if(is_full()) {
		cout << "El arreglo está lleno" << endl;
		return;
	}
	
	back = next(back);
	
	array[back] = data;
	++lenght;
}

template <class T>
void CircularArray<T>::insert(T data, int pos) {
	if(is_full()) {
		cout << "El arreglo está lleno" << endl;
		return;
	}

	if(pos > capacity-1 || pos < 0 || pos > lenght+1){
		cout << "La posición no es válida" << endl;
		return;
	}

	if(is_empty()) {
		push_front(data);
		return;
	}

	pos = (front + pos) % capacity;

	for(size_t i = next(back); i != pos; i = prev(i)) {
		array[i] = array[prev(i)];
	}

	array[pos] = data;

	++lenght;
}

template <class T>
T CircularArray<T>::pop_front() {
	if(is_empty()) {
		throw invalid_argument("El arreglo está vacío, no hay nada para borrar");
	} 

	front = next(front);
	lenght--;
	return array[prev(front)];
}

template <class T>
T CircularArray<T>::pop_back() {
	if(is_empty()) {
		throw invalid_argument("El arreglo está vacío, no hay nada para borrar");
	} 

	back = prev(back);
	lenght--;
	return array[next(back)];
}

template <class T>
bool CircularArray<T>::is_full() {
	// cout << "capacity == lenght - 1: " << capacity  << " " << lenght << '\n';
	return capacity == lenght;
}

template <class T>
bool CircularArray<T>::is_empty() {
	return lenght == 0;
}

template <class T>
int CircularArray<T>::size() {
	return lenght;
}

template <class T>
void CircularArray<T>::clear() {
	lenght = 0;
	front = back = -1;
}

template <class T>
T& CircularArray<T>::operator[](int i) {
	if(is_empty() || i > capacity-1 || i < 0)
		throw invalid_argument("No fue posible retornar un valor");
	return array[(front + i) % capacity];
}

template <class T>
void swap(T* a, T* b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void CircularArray<T>::sort() {
	for(int i = 0; i < lenght-1; ++i) 
		for(int j = 0; j < lenght-1-i; ++j) 
			if((*this)[j] > (*this)[j+1]) 
				swap((*this)[j], (*this)[j+1]);
}


template <class T>
bool CircularArray<T>::is_sorted() {
	int contador = front;
	for(int i = 0; i<lenght-1; i++) {
		if(array[contador] < array[prev(contador)]) 
			return false;
		contador = next(contador);
	}
	return true;
}

template <class T>
void CircularArray<T>::reverse() {
	T *tmp = new T[capacity];
	int contador = 0;

	for(int i=size()-1; i>=0; i--) {
		tmp[contador] = (*this)[i];
		contador++;
	}

	for(int i=size()-1; i>=0; i--) {
		(*this)[i] = tmp[i];
	}
}


template <class T>
string CircularArray<T>::to_string(string sep) {
	string result = "";
	for(int i = 0; i < size(); i++) {
		result += std::to_string((*this)[i]) + sep;
	}
	return result;
}
