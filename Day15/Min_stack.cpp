class MinStack {
public:
    stack<int> s;
    stack<int> mini;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        //to push min element into mini stack
        if(mini.size() < 1 || val <= mini.top())
        {
            mini.push(val);
        }
    }
    
    void pop() {
        if(mini.top() == s.top())
        {
            mini.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
