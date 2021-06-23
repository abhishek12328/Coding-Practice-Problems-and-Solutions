/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

------------------------------------------------------
------------------------------------------------------*/

stack<int>st1,st2;
MinStack::MinStack() {
  while(!st1.empty()){
      st1.pop();
  }
  while(!st2.empty()){
      st2.pop();
  }
}

void MinStack::push(int x) {
    st1.push(x);
    if(st2.empty()){
        st2.push(x);
    }else{
        st2.push(min(st2.top(),x));
    }
}

void MinStack::pop() {
    if(!st1.empty()){
       st1.pop();
       st2.pop();
    }
}

int MinStack::top() {
    if(st1.empty())return -1;
    return st1.top();
}

int MinStack::getMin() {
    if(st1.empty())return -1;
    return st2.top();
}
