class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        visited[0][0][0] = true;
        int res = 0;
        q.push({0,0,0});
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                int r = node[0],c = node[1], ob = node[2];
                if(r==n-1 && c == m-1) return res;
                for(auto dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    int nk = ob;
                    if(nr>=0 && nr<n && nc>=0 && nc<m) {
                        if(grid[nr][nc]==1) {
                            nk++;
                        }
                        if(nk <= k && !visited[nr][nc][nk]) {
                            visited[nr][nc][nk] = true;
                            q.push({nr,nc,nk});
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};