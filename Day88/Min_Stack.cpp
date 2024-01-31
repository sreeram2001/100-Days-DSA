class MinStack {
public:

    //we use a stack to store the pair , the pair will have element and minimum element until the current element
    stack< pair<int, int> > stac;

    MinStack() {
    }
    
    void push(int val) {
        
        if(stac.empty())
        {
            stac.push({val ,val});
        }
        else
        {
            stac.push({val, min(val, getMin())});
        }
    }
    
    void pop() {
        stac.pop();
    }
    
    int top() {
        return stac.top().first;
    }
    
    int getMin() {
        auto topp = stac.top();
        return topp.second;
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
