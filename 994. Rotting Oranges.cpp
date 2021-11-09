class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> gri(n,vector<int> (m,-1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    gri[i][j] = 0;
                    queue<vector<int>> q;
                    vector<vector<int>> visited(n,vector<int> (m,0));
                    q.push({i,j});
                    int cnt = 0;
                    while(!q.empty()) {
                        queue<vector<int>> q1;
                        while(!q.empty()) {
                            auto a = q.front();
                            q.pop();
                            visited[a[0]][a[1]] = 1;
                            if(gri[a[0]][a[1]]==-1) gri[a[0]][a[1]] = cnt;
                            else gri[a[0]][a[1]] = min(gri[a[0]][a[1]],cnt);
                            if(a[0] > 0 && grid[a[0]-1][a[1]]==1 && visited[a[0]-1][a[1]]==0) {
                                q1.push({a[0]-1,a[1]});
                            }
                            if(a[0] < n-1 && grid[a[0]+1][a[1]]==1 && visited[a[0]+1][a[1]]==0) {
                                q1.push({a[0]+1,a[1]});
                            }
                            if(a[1] > 0 && grid[a[0]][a[1]-1]==1 && visited[a[0]][a[1]-1]==0) {
                                q1.push({a[0],a[1]-1});
                            }
                            if(a[1] < m-1 && grid[a[0]][a[1]+1]==1 && visited[a[0]][a[1]+1]==0) {
                                q1.push({a[0],a[1]+1});
                            }
                        }
                        q = q1;
                        cnt++;
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] && gri[i][j]==-1) return -1;
                // cout << gri[i][j] << " ";
                if(grid[i][j] && res < gri[i][j]) res = gri[i][j];
            }
            // cout << endl;
        }
        return res;
    }
};