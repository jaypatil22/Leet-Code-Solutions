class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int cnt;
    KthLargest(int k, vector<int>& nums) {
        // q.clear();
        for(int i=0;i< nums.size();i++) {
            q.push(nums[i]);
        }
        cnt = k;
    }
    
    int add(int val) {
        int res;
        vector<int> a;
        q.push(val);
        int cnt1 = cnt;
        while(q.size()>cnt) {
            res = q.top();
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */