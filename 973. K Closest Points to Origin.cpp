class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++) {
            pair<int,int> entry = {points[i][0]*points[i][0]+points[i][1]*points[i][1],i};
            if(pq.size() < k) {
                pq.push(entry);
            } else if(entry.first < pq.top().first) {
                pq.pop();
                pq.push(entry);
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            int i = pq.top().second;
            pq.pop();
            res.push_back(points[i]);
        }
        return res;
    }
};