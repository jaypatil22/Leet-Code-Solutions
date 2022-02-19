class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, min_n = INT_MAX;
        priority_queue<int> pq;
        for(int &a : nums) {
            if(a%2) {
                a = a*2;
            }
            pq.push(a);
            min_n = min(min_n,a);
        }
        while(pq.top()%2==0) {
            res = min(res,pq.top()-min_n);
            min_n = min(min_n,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res,pq.top()-min_n);
    }
};