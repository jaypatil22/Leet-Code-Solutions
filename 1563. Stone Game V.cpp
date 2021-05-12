class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> memo;
    int dp(vector<int> &a,int i,int j) {
        if(i==j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        memo[i][j]=0;
        for(int p=i+1;p<=j;p++) {
            int l=prefix[p]-prefix[i],r=prefix[j+1]-prefix[p];
            if(l<r) {
                memo[i][j] = max(memo[i][j],l+dp(a,i,p-1));
            } else if(r<l) {
                memo[i][j] = max(memo[i][j],r+dp(a,p,j));
            } else {
                memo[i][j] = max(memo[i][j],max(l+dp(a,i,p-1),r+dp(a,p,j)));
            }
        }
        // for(int k=0;k<memo.size();k++) {
        //     for(int l=0;l<memo.size();l++) {
        //         cout << memo[k][l] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return memo[i][j];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n+1,0);
        memo.resize(n,vector<int> (n,-1));
        for(int i=0;i<n;i++) {
            prefix[i+1]+=prefix[i]+stoneValue[i];
        }
        return dp(stoneValue,0,n-1);
        
    }
};