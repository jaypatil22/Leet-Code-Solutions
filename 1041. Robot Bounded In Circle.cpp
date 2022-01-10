class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0,y = 0,d= 0;
        vector<vector<int>> steps = {{0,1},{1,0},{0,-1},{-1,0}};
        for(char ch : instructions) {
            if(ch=='R') {
                d = (d+1)%4;
            } else if(ch=='L') {
                d = (d+3)%4;
            } else {
                x += steps[d][0],y+=steps[d][1];
            }
        }
        return x==0 && y==0 || d > 0;
    }
};