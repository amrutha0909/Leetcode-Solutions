class MinStack {
public:
    vector<int>arr;
    int t;
    MinStack() {
        t=0;
    }
    
    void push(int val) {
        t++;
        arr.push_back(val);
    }
    
    void pop() {
        t--;
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        int minEl=INT_MAX;
        for(int num:arr){
            minEl=min(minEl,num);
        }
        return minEl;
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