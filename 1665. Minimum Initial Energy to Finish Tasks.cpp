class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        int res = tasks[0][1],prev = tasks[0][1], rem = tasks[0][1]-tasks[0][0];
        for(int i=1;i<tasks.size();i++) {
            if(tasks[i][1] > rem) {
                res += tasks[i][1] - rem;
                rem = tasks[i][1] - tasks[i][0];
            } else {
                rem = rem - tasks[i][0];
            }
        }
        return res;
    }
};