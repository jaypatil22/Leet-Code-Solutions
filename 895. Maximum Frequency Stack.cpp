class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int mf;
    FreqStack() {
        freq.clear();
        group.clear();
        mf = 0;
    }
    
    void push(int val) {
        freq[val] = freq.find(val)!=freq.end() ? freq[val] +1 : 1;
        if(freq[val] > mf) mf = freq[val];
        group[freq[val]].push(val);
    }
    
    int pop() {
        int x = group[mf].top();group[mf].pop();
        freq[x] -= 1;
        if(group[mf].size() == 0)
            mf--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */