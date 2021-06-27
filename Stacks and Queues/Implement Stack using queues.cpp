class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
        while(!q.empty()){
            q.pop();
        }
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q1;
        while(!q.empty()){
            q1.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop(){
        if(!q.empty()){
            int t = q.front();
            q.pop();    
            return t;
        }
        else return -1;
    }
    
    /** Get the top element. */
    int top() {
        if(!q.empty()){
            int t = q.front();
            return t;
        }
        else return -1;    
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.size()) return 0;
        return 1;   
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
