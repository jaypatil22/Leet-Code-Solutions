class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(),stones.end());
        while(q.size() > 1) {
            int a = q.top();q.pop();
            int b = q.top();q.pop();
            if(a==b) continue;
            else q.push(a-b);
        }
        return q.size()==0 ? 0 : q.top();
    }
};