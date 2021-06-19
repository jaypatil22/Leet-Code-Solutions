class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        if(m==1 && n==1) return {0,0};
        if(m > n) {
            int l = 0,r=m;
            while(l<r) {
                int central = (l+r+1)/2;
                int max = INT_MIN,col=-1,row=-1;
                for(int i=central-1;i<=central+1;i++) {
                    for(int j=0;j<n;j++) {
                        if(i==-1 || i==m) continue;
                        if(mat[i][j]>max) {
                            max = mat[i][j];
                            col = i;
                            row = j;
                        }
                    }
                }
                if(col == central) return {col,row};
                if(col == central-1) {
                    r = central;
                } else {
                    l = central;
                }
            }
        } else {
            int l = 0,r=n;
            while(l<r) {
                int central = (l+r+1)/2;
                int max = INT_MIN,col=-1,row=-1;
                for(int i=central-1;i<=central+1;i++) {
                    for(int j=0;j<m;j++) {
                        if(i==-1 || i==n) continue;
                        if(mat[j][i]>max) {
                            max = mat[j][i];
                            col = i;
                            row = j;
                        }
                    }
                }
                if(col == central) return {row,col};
                if(col == central-1) {
                    r = central;
                } else {
                    l = central;
                }
            }
        }
        return {0,0};
    }
};