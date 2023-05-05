class MyQueue {
public:
    stack<int> q;
    stack<int> temp_q;

    MyQueue() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        while(!q.empty())
        {
            temp_q.push(q.top());
            q.pop();
        }
        //return popped value
        int popp = temp_q.top();
        temp_q.pop();

        //now push the elements back to main queue
        while(!temp_q.empty())
        {
            q.push(temp_q.top());
            temp_q.pop();
        }
        return popp;
    }
    
    int peek() {
        while(!q.empty())
        {
            temp_q.push(q.top());
            q.pop();
        }

        //return front element
        int popp = temp_q.top();

        //now push the elements back to main queue
        while(!temp_q.empty())
        {
            q.push(temp_q.top());
            temp_q.pop();
        }
        return popp;
    }
    
    bool empty() {
        return q.empty();
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
