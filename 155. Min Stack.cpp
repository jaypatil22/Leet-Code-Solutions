class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    int size;
    vector<int> minstack;

    MinStack() {
        size=0;
    }

    void push(int x) {
        if(size==0) {
            size++;
            stack.emplace_back(x);
            minstack.emplace_back(x);
        } else {
            stack.emplace_back(x);
            int temp = min(x,minstack[size-1]);
            minstack.emplace_back(temp);
            size++;
        }

    }

    void pop() {
        size--;
        stack.resize(size);
        minstack.resize(size);
    }

    int top() {
        return stack[size-1];
    }

    int getMin() {
        return minstack[size-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
