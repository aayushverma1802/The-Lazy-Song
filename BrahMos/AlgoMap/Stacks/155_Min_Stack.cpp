class MinStack {
public:    stack<int>temp;
    stack<int>mini;
    MinStack() {
        
    }

    void push(int val) {
        if(mini.empty()==true or mini.top()>=val){
            mini.push(val);
        }
        temp.push(val);
    }
    
    void pop() {
        if(temp.top()==mini.top()){
            mini.pop();
        }
        temp.pop();
    }
    
    int top() {
        return temp.top();
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