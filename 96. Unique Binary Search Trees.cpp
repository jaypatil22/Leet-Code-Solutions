class Solution {
public:
    int numTrees(int n) {
        vector<int> cat(n+1);
        cat[0] = 1;
        cat[1] = 1;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                cat[i] += cat[j-1] * cat[i-j];
            }
        }
        return cat[n];
    }
};