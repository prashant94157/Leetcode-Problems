class MinStack {
    stack<long> s;
    int mini;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.size()==0)
        {
            s.push(val);
            mini = val;
        }
        else if(val > mini)
        {
            s.push(val);
        }
        else
        {
            s.push(2L*val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(mini < s.top())
            s.pop();
        else
        {
            mini = 2L*mini - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(mini > s.top())
            return mini;
        else return s.top();
    }
    
    int getMin() {
        return mini;
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