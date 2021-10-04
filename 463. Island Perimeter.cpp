class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]) {
                    if(i==0) res++;
                    else if(!grid[i-1][j]) res++;
                    if(j==0) res++;
                    else if(!grid[i][j-1]) res++;
                   if(i==grid.size()-1) res++;
                    else if(!grid[i+1][j]) res++;
                    if(j==grid[0].size()-1) res++;
                    else if(!grid[i][j+1]) res++;
                }
            }
        }
        return res;
    }
};