class MinStack {
public:
vector<pair<int,int>>stk;
unordered_map<int,int>mp;
int minval=INT_MAX;
    MinStack() {
        vector<pair<int,int>>stk;
        unordered_map<int,int>mp;
        int minval;
    }
    
    void push(int val) {
        minval = min(minval, val);
        stk.push_back({val,minval});
        mp[val]++;
    }
    
    void pop() {
        int v = stk.back().first;
        stk.pop_back();
        mp[v]--;
        if(mp[minval]==0){
            if(stk.size()==0) minval=INT_MAX;
            else minval = stk.back().second;
        }

    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
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