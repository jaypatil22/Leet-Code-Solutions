class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat.size()==0) return true;
        if(target == mat) return true;
        int n = mat.size();
        for(int i=0;i<3;i++) {
            for(int k=0;k<n;k++) {
                for(int j=k+1;j<n;j++) {
                    swap(mat[k][j],mat[j][k]);
                }
            }
            for(int k=0;k<n;k++) {
                for(int j=0,m=n-1;j<n/2;j++,m--) {
                    swap(mat[k][j],mat[k][m]);
                }
            }
            if(mat == target) return true;
        }
        return false;
    }
};