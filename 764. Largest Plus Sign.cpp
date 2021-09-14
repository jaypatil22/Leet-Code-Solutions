class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> arr(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++) {
            arr[mines[i][0]][mines[i][1]] = 0;
        }
        vector<vector<int>> up(arr),down(arr),right(arr),left(arr);
        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(up[i][j]) {
                    up[i][j] += up[i-1][j];
                }
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(left[j][i]) {
                    left[j][i] += left[j][i-1];
                }
            }
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                if(right[i][j]) {
                    right[i][j] += right[i][j+1];
                }
            }
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                if(down[j][i]) {
                    down[j][i] += down[j+1][i];
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {  
                if(arr[i][j]) {
                    int cur = INT_MAX;
                    cur = min(cur,up[i][j]);
                    cur = min(cur,down[i][j]);
                    cur = min(cur,right[i][j]);
                    cur = min(cur,left[i][j]);
                    if(cur > res) res = cur;
                }
            }
        }
        return res;
    }
};