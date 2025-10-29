#include <iostream>
#include <cassert>
using namespace std;

// simple trick to avoid re-changing the class
typedef int type;

class Stack {
private:
	int size { };
	int top { };
	type* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new type[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(type x) {
		assert(!isFull());
		array[++top] = x;
	}

	type pop() {
		assert(!isEmpty());
		return array[top--];
	}

	type peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};

int reverse_number(int num) {
  if (num == 0)
    return 0;
  
  Stack stk(25);
  while(num) 
    stk.push(num % 10), num /= 10;
  
  int tens = 1;
  while(!stk.isEmpty())
    num = stk.pop() * tens + num, tens *= 10;
  return num;  
 }



int main() {
  return 0;
}