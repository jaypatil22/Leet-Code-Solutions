class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<unordered_set<int>> col(n),row(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                col[j].insert(matrix[i][j]);
                row[i].insert(matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++) {
            if(col[i].size() != n || row[i].size()!= n) return false;
        }
        return true;
    }
};