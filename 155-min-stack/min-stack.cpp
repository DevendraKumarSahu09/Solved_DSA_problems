class MinStack {
public:

    vector<pair<int, int> > stAck;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stAck.empty()){
            pair<int, int> p = make_pair(val, val);
            stAck.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, stAck.back().second );
            stAck.push_back(p);
        }
    }
    
    void pop() {
        stAck.pop_back();
    }
    
    int top() {
        return stAck.back().first;
    }
    
    int getMin() {
        return stAck.back().second;
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