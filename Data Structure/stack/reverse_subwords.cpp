#include <iostream>
#include <cassert>
using namespace std;

// simple trick to avoid re-changing the class
typedef char type;

class Stack {
  private:
    int size {};
    int top {};
    type*  array {};
  public:
  Stack(int size):
    size(size), top(-1) {
      array = new type[size];
    }
  
  ~Stack() {
    delete[] array;
  }

  void push(type val) {
    assert(!isFull());
    array[++top] = val;
  }

  type pop() {
    assert(!isEmpty());
    return array[top--];
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

string reverse_subwords(string line) {
  string result;

  line+= ' ';
  Stack stk(line.size());

  for (int i = 0; i < (int) line.size(); ++i) {
    if (line[i] == ' '){ // get content (now reversed)
        while(!stk.isEmpty()) {
          result+= stk.pop();
        }
        result += ' ';
    } else {
      stk.push(line[i]);
    }
  }
  return result;
}

int main() {
  return 0;
}