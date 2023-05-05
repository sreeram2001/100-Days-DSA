class MyStack {
public:
    queue<int> stack;
    queue<int> temp_stack;

    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        
        while(stack.size() > 1)
        {
            temp_stack.push(stack.front());
            stack.pop();
        }
        int popp = stack.front();
        stack.pop();

        while(!temp_stack.empty())
        {
            stack.push(temp_stack.front());
            temp_stack.pop();
        }
        return popp;
    }
    
    int top() {
        return stack.back();
    }
    
    bool empty() {
        return stack.empty();
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
