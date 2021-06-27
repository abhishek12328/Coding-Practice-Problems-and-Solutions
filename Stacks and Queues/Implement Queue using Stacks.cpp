class MyQueue {
public:
    stack<int> q;

    /** Initialize your data structure here. */
    MyQueue() {
        while(!q.empty()){
            q.pop();
        }      
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
      stack<int> q1;
        while(!q.empty()){
            q1.push(q.top());
            q.pop();
        }
        q.push(x);
        while(!q1.empty()){
            q.push(q1.top());
            q1.pop();
        }
  
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!q.empty()){
            int t = q.top();
            q.pop();    
            return t;
        }
        else return -1;
    
        
    }
    
    /** Get the front element. */
    int peek() {
         if(!q.empty()){
            int t = q.top();
            return t;
        }
        else return -1;    
    
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
         if(q.size()) return 0;
        return 1;   
       
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
