#include <iostream>
#include <vector>
#include <stack>
using  namespace std;



/*
Step-by-Step Mechanism

We maintain a stack of indices whose next greater element hasn’t been found yet.

Each time we get a new number v[i], we:

Compare it with the element at the top of the stack (that is, v[pos.top()]).

If v[i] > v[pos.top()], that means v[i] is the next greater element for v[pos.top()].

So, we store the index i in v[pos.top()].

Then pop that index from the stack (because it’s now resolved).

Keep doing this while the new element v[i] is greater than the top of the stack.

When we find an element >= v[i], stop — because it "shields" the smaller ones behind it.

Finally, push i (the current index) into the stack, waiting for its own next greater element.

After we finish iterating, anything left in the stack has no next greater → assign -1.

*/


vector<int> next_greater_idx(vector<int>& v) {
  stack<int> pos;

  for (int i = 0; i < (int) v.size(); ++i) {
    while(!pos.empty() && v[i] > v[pos.top()])
      v[pos.top()] = i, pos.pop();
    pos.push(i);  
  }

  // left in the stack has no next greater -> -1
  while(!pos.empty())
    v[pos.top()] = -1, pos.pop();
  return v;  
}