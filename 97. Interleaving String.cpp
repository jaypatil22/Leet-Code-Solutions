class Solution {
    bool helper(string s1,int i,string s2,int j,string s3,int k,vector<vector<int>> &dp) {
        // cout << i << " " << j << endl;
        if(i==s1.size()) {
            return s3.substr(k)==s2.substr(j);
        }
        if(j==s2.size()) {
            return s3.substr(k)==s1.substr(i);
        }
        if(dp[i][j]!=-1) return dp[i][j]?true:false;
        bool ans = false;
        if(s1[i]==s3[k]) {
            ans |= helper(s1,i+1,s2,j,s3,k+1,dp);
        }
        if(s2[j]==s3[k]) {
            ans |= helper(s1,i,s2,j+1,s3,k+1,dp);
        }
        dp[i][j] = ans ? 1:0;
        return ans;
    } 
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m=s2.size(),t = s3.size();
        if(n+m != t) return false;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0&&j==0) {
                    dp[i][j] = true;
                } else if(i==0) {
                    dp[i][j] = dp[i][j-1] && s3[i+j-1] == s2[j-1];
                } else if(j==0) {
                    dp[i][j] = dp[i-1][j] && s3[i+j-1] == s1[i-1];
                } else {
                    dp[i][j] = (dp[i-1][j]&& s1[i-1]==s3[i+j-1]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};