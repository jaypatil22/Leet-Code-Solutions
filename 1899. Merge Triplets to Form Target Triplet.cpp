class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool res = false;
        int x = INT_MIN,y=INT_MIN,z=INT_MIN;
        for(int i=0;i<triplets.size();i++) {
            if(triplets[i][0]==target[0] || triplets[i][1]==target[1] || triplets[i][2]==target[2]) {
                if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) continue;
                x = max(x,triplets[i][0]);
                y = max(y,triplets[i][1]);
                z = max(z,triplets[i][2]);
            }
        }
        if(x==target[0] && y == target[1] && z == target[2]) return true;
        return false;
    }
};