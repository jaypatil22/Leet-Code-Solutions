class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int> (n,0));
        int cnt = 1,left = 0, right = n-1, top = 0, bottom = n-1;
        int dir = 1;
        while(cnt <= n*n) {
            if(dir==1) {
                dir++;
                for(int j=left;j<=right;j++) {
                    res[top][j] = cnt++;
                }
                top++;
            } else if(dir==2) {
                dir++;
                for(int i=top;i<=bottom;i++) {
                    res[i][right] = cnt++;
                }
                right--;
            } else if(dir==3) {
                dir++;
                for(int j=right;j>=left;j--) {
                    res[bottom][j] = cnt++;
                }
                bottom--;
            } else {
                dir = 1;
                for(int i=bottom;i>=top;i--) {
                    res[i][left] = cnt++;
                }
                left++;
            }
        }
        return res;
    }
};