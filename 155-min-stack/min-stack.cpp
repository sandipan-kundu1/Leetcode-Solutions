class MinStack {
    stack<pair<int,int>> s;
public:
    MinStack() {
    }
    
    void push(int val) {        
        int mini=(s.empty())? val : min(s.top().second, val);
        s.push({val,mini});
    }
    
    void pop() {
        if(!s.empty())
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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