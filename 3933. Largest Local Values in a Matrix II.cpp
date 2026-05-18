class Solution {
public:
    // sparse table / prefix approach: build 2D prefix max
    // rangeMax(r1,c1,r2,c2) in O(1)
    
    vector<vector<int>> pmax; // prefix max — but 2D range max needs sparse table
    // Simpler: just use 2D prefix where we answer with inclusion-exclusion
    // Actually for max (not sum), we need 2D sparse table. 
    // For competitive constraints, a 2D sliding window or just prefix-based check works.

    int n, m;
    vector<vector<int>>* mat;

    // 2D sparse table for range max query in O(1)
    // st[k1][k2][i][j] = max in 2^k1 rows x 2^k2 cols block starting at (i,j)
    vector<vector<vector<vector<int>>>> st;
    vector<int> log2_;

    void buildSparseTable(vector<vector<int>>& matrix) {
        int K1 = __lg(n) + 1, K2 = __lg(m) + 1;
        st.assign(K1, vector<vector<vector<int>>>(K2, vector<vector<int>>(n, vector<int>(m, 0))));
        
        // base
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                st[0][0][i][j] = matrix[i][j];
        
        // extend along columns
        for(int k2 = 1; k2 < K2; k2++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j + (1<<k2) <= m; j++)
                    st[0][k2][i][j] = max(st[0][k2-1][i][j], st[0][k2-1][i][j+(1<<(k2-1))]);
        
        // extend along rows
        for(int k1 = 1; k1 < K1; k1++)
            for(int k2 = 0; k2 < K2; k2++)
                for(int i = 0; i + (1<<k1) <= n; i++)
                    for(int j = 0; j < m; j++)
                        if(j + (1<<k2) <= m || k2 == 0)
                            st[k1][k2][i][j] = max(st[k1-1][k2][i][j], st[k1-1][k2][i+(1<<(k1-1))][j]);
    }

    int queryMax(int r1, int c1, int r2, int c2) {
        if(r1 > r2 || c1 > c2) return 0;
        int k1 = __lg(r2 - r1 + 1), k2 = __lg(c2 - c1 + 1);
        return max({
            st[k1][k2][r1][c1],
            st[k1][k2][r2-(1<<k1)+1][c1],
            st[k1][k2][r1][c2-(1<<k2)+1],
            st[k1][k2][r2-(1<<k1)+1][c2-(1<<k2)+1]
        });
    }

    bool check(int i, int j, int x) {
        int r1 = max(0, i-x), r2 = min(n-1, i+x);
        int c1 = max(0, j-x), c2 = min(m-1, j+x);

        // We need max excluding the 4 corners
        // Split the window into 3 horizontal strips to exclude corners:
        // top strip: row r1, cols (c1+1)..(c2-1)  [exclude corner cols]
        // middle:    rows (r1+1)..(r2-1), cols c1..c2
        // bottom:    row r2, cols (c1+1)..(c2-1)
        // But corner exclusion only applies when the corner is exactly at boundary
        // Simpler: query full rectangle, then check if max comes only from corners

        // Actually: corners are only (r1,c1),(r1,c2),(r2,c1),(r2,c2) when they
        // are exactly x away in BOTH dimensions. Split into strips:
        
        int maxVal = 0;
        // top row (exclude corners if at boundary)
        bool topIsBoundary = (i - r1 == x);
        bool botIsBoundary = (r2 - i == x);
        bool leftIsBoundary = (j - c1 == x);
        bool rightIsBoundary = (c2 - j == x);

        // middle rows: full width
        if(r1+1 <= r2-1)
            maxVal = max(maxVal, queryMax(r1+1, c1, r2-1, c2));

        // top row
        if(topIsBoundary) {
            if(c1+1 <= c2-1) maxVal = max(maxVal, queryMax(r1, c1+1, r1, c2-1)); // exclude corners
            // include edge cells (not corners)
            if(!leftIsBoundary)  maxVal = max(maxVal, queryMax(r1, c1, r1, c1));
            if(!rightIsBoundary) maxVal = max(maxVal, queryMax(r1, c2, r1, c2));
        } else {
            maxVal = max(maxVal, queryMax(r1, c1, r1, c2));
        }

        // bottom row
        if(r2 != r1) {
            if(botIsBoundary) {
                if(c1+1 <= c2-1) maxVal = max(maxVal, queryMax(r2, c1+1, r2, c2-1));
                if(!leftIsBoundary)  maxVal = max(maxVal, queryMax(r2, c1, r2, c1));
                if(!rightIsBoundary) maxVal = max(maxVal, queryMax(r2, c2, r2, c2));
            } else {
                maxVal = max(maxVal, queryMax(r2, c1, r2, c2));
            }
        }

        return maxVal <= x;
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        buildSparseTable(matrix);
        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] != 0)
                    res += check(i, j, matrix[i][j]);
        return res;
    }
};