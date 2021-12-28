class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int K = s.size();
        vector<int> dp(K+1,0);
        dp[K] = 1;
        
        for(int i=K-1;i>=0;i--) {
            for(string d : digits) {
                if(stoi(d) < s[i]-'0') {
                    dp[i] += pow(digits.size(),K-i-1);
                } else if(stoi(d) == s[i]-'0') {
                    dp[i] += dp[i+1];
                }
            }
        }
        for(int i=1;i<K;i++) {
            dp[0] += pow(digits.size(),i);
        }
        return dp[0];
    }
};