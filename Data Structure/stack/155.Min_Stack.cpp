#include <iostream>
#include <stack>
using namespace std;

class MinStck {
  private:
    stack <int> data; 
    stack <int> min_stk;
  public:
    void push(int val) {
      data.push(val);
      if (min_stk.empty()) 
        min_stk.push(val);
      else 
      // add prefix_min at top of stack
        min_stk.push(min(val, min_stk.top()));  
    }
    
    void pop() {
      if (min_stk.top() == data.top())
        min_stk.pop();
      data.pop();  
    }

    int top() {
      return data.top();
    }

    int getMin() {
      return min_stk.top();
    }
};

int main(){
  return 0;
}