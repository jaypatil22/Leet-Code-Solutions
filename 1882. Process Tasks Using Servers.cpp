class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> free,working;
        for(int i=0;i<servers.size();i++) {
            free.push({servers[i],0,i});
        }
        vector<int> res;
        for(int i=0;i<tasks.size();i++) {
            while(!working.empty() && (working.top()[0] <= i || free.empty())) {
                free.push({working.top()[1],(working.top()[0]<=i)?0:working.top()[0],working.top()[2]});
                working.pop();
            }
            res.push_back(free.top()[2]);
            working.push({tasks[i] + max(free.top()[1],(long long)i),free.top()[0],free.top()[2]});
            free.pop();
        }
        return res;
    }
};