class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> preRow(m+2,vector<int>(n+2)),preCol(preRow),d1(preRow),d2(preRow);
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                preRow[i][j] += preRow[i][j-1] + grid[i-1][j-1];
                preCol[i][j] += preCol[i-1][j] + grid[i-1][j-1];
                d1[i][j] += d1[i-1][j-1] + grid[i-1][j-1];
                d2[i][j] += d2[i-1][j+1] + grid[i-1][j-1];
            }
        }
        int res = 0;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                for(int k=min(m-i,n-j);k>res;k--) {
                    int s_d1 = d1[i+k][j+k] - d1[i-1][j-1];
                    int s_d2 = d2[i+k][j] - d2[i-1][j+k+1];
                    bool match = s_d2 == s_d1;
                    for(int l = 0;l<k && match;l++) {
                        match &= s_d1 == preRow[i+l][j+k] - preRow[i+l][j-1];
                        match &= s_d1 == preCol[i+k][j+l] - preCol[i-1][j+l];
                    }
                    if(match) res = k;
                }
            }
        }
        return res+1;
    }
};