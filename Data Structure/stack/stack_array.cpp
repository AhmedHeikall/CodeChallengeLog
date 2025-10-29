#include <iostream>
#include <cassert>
using namespace std;

class Stack {
  private:
    int size {};
    int top {};
    int*  array {};
  public:
  Stack(int size):
    size(size), top(-1) {
      array = new int[size];
    }
  
  ~Stack() {
    delete[] array;
  }

  void push(int val) {
    assert(!isFull());
    array[++top] = val;
  }

  void pop() {
    assert(!isEmpty());
    array[top--];
  }

  int peek() {
    assert(!isEmpty());
    return array[top];
  }
  
  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == size - 1;
  }

  void display() {
    for (int i = top; i >= 0; i--)
      cout << array[i] << ' ';
    cout << '\n';  
  }

};

int main() {

  return 0;
}