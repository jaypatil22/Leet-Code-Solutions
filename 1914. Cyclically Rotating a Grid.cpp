class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int smaller = m<n ? m : n;
        vector<vector<int>> res(m, vector<int>(n, 0)), inter(smaller/2);
        for(int i=0;i<smaller/2;i++) {
            // vector<int> nn;
            for(int j=i;j<n-i;j++) {
                inter[i].push_back(grid[i][j]);
            }
            for(int j=i+1;j<m-i;j++) {
                inter[i].push_back(grid[j][n-i-1]);
            }
            for(int j=n-i-2;j>=i;j--) {
                inter[i].push_back(grid[m-i-1][j]);
            }
            for(int j=m-i-2;j>i;j--) {
                inter[i].push_back(grid[j][i]);
            }
            // if(nn.size()!=0) {
            //     inter.push_back(nn);
            // }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i=0;i<smaller/2;i++) {
            int n_k = k%((n-2*i)*2+(m-2*i)*2-4);
            int l = 0;
            int size = inter[i].size();
            // cout << i << " ";
            for(int j=i;j<n-i;j++) {
                res[i][j] = inter[i][(l+n_k)%size];
                l++;
            }
            for(int j=i+1;j<m-i;j++) {
                res[j][n-i-1] = inter[i][(l+n_k)%size];
                l++;
            }
            for(int j=n-i-2;j>=i;j--) {
                res[m-i-1][j] = inter[i][(l+n_k)%size];
                l++;
            }
            for(int j=m-i-2;j>i;j--) {
                res[j][i] = inter[i][(l+n_k)%size];
                l++;
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        return res;
    }
};