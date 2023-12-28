// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// при вставке в полный стек должна перевыдел€тьс€ пам€ть

#include<iostream>

const int MaxSize = 1000;
template<class T>
class TStack {
	T* data;
	int size;
	int top;
public:
	TStack() : top(-1), size(MaxSize) {
		data = new T[size]();
	};

	TStack(int _size) {
		if (_size<0 || _size>MaxSize) {
			throw "error";
		}
			size = _size;
			top = -1;
			data = new T[size]();
		
	}

	size_t ssize() const { return top + 1; }
	bool isEmpty()noexcept {

		if (top == -1) {
			return true;
		}
		else return false;
	}

	void push(const T& dat) {
		if (top + 1 == size) {
			T* buf = new T[size]();
			std::copy(data, data + size, buf);
			delete[] data;
			data = buf;
			size = size * 2;
		}
		data[++top] = dat;

	}
	T pop() {
		if (!isEmpty())
			return data[top--];
	}
	T Top() {
		return data[top];
	}
	~TStack() {
		delete[] data;
	}
};

		
