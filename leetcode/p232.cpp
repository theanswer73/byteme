#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
  stack<int> in;
  stack<int> out;
  /** Initialize your data structure here. */
  MyQueue() {
    
  }
  
  /** Push element x to the back of queue. */
  void push(int x) {
    in.push(x); 
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // make true `out` is not empty so it contains front number
    int x = peek();  
    out.pop();      
    return x;
  }
  
  /** Get the front element. */
  int peek() {
    // only push into `out` when `out` is empty 
    // otherwise it will break the order of queue
    if (out.empty()) { 
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }    
    } 
    return out.top();
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return in.empty() && out.empty();    
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
