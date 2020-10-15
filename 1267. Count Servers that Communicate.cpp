class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res=0;
        vector<int> col(grid[0].size(),0);
        vector<int> row(grid.size(),0);
        for(int i =0;i<grid.size();i++) {
            for(int j = 0;j<grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    col[j]++;
                    row[i]++;
                }
            }
        }
        for(int i =0;i<grid.size();i++) {
            for(int j = 0;j<grid[i].size();j++) {
                if(grid[i][j] && (row[i] > 1 || col[j] > 1))
                    res++;
            }
        }
        return res;
    }
};
