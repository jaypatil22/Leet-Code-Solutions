class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<vector<int>> d1(grid.size()+2,vector<int>(grid[0].size()+2,0)),d2(d1);
        for(int i=1;i<=grid.size();i++) {
            for(int j=1;j<=grid[0].size();j++) {
                d1[i][j] += d1[i-1][j-1] + grid[i-1][j-1];
                d2[i][j] += d2[i-1][j+1] + grid[i-1][j-1];
            }
        }
        // for(int i=0;i<d2.size();i++) {
        //     for(int j= 0;j<d2[0].size();j++) {
        //         cout<< d2[i][j] << " ";
        //     }
        //     cout <<endl;
        // }
        set<int> pq; 
        int n = grid[0].size(),m = grid.size();
        for(int i=1;i<=grid.size();i++) {
            for(int j=1;j<=grid[0].size();j++) {
                pq.insert(grid[i-1][j-1]);
                if(pq.size()>3) pq.erase(pq.begin());
                for(int k=1;j-k>=1 && j+k<=n && i+2*k<=m;k++) {
                    int sum = d1[i+k][j+k]-d1[i-1][j-1] + d2[i+2*k][j] - d2[i+k-1][j+k+1] + d1[i+2*k][j] - d1[i+k-1][j-k-1] + d2[i+k][j-k] - d2[i-1][j+1]-grid[i-1][j-1]-grid[i+k-1][j+k-1]-grid[i+2*k-1][j-1]-grid[i+k-1][j-k-1];
                    pq.insert(sum);
                    // cout << i << " " << j << " " << k << " " << sum << endl;
                    // cout << grid[i-1][j-1] << " " << grid[i+k-1][j+k-1] << " " << grid[i+2*k-1][j-1] << " " << grid[i+k-1][j-k-1] << endl;            
                    if(pq.size() > 3) pq.erase(pq.begin());
                }
            }
        }
        vector<int> res(pq.rbegin(),pq.rend());
        return res;
    }
};