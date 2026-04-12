class Solution {
public:
    int move(string& word, int pos, int new_pos) {
        if(pos == 0) return 0;
        int g_pos = word[pos-1] - 'A';
        int n_g_pos = word[new_pos] - 'A';
        int g_pos_x = g_pos/6;
        int g_pos_y = g_pos%6;
        int n_g_pos_x = n_g_pos/6;
        int n_g_pos_y = n_g_pos%6;
        int res = abs(g_pos_x - n_g_pos_x) + abs(g_pos_y - n_g_pos_y);
        return res;
    }
    void traverse(vector<vector<int>>& dp, string& word, int f_p, int s_p, int w_c, int moves) {
        if(w_c > word.size()) return;
        if(dp[f_p][s_p] <= moves) return;
        dp[f_p][s_p] = moves;
        int move_f = move(word, f_p, w_c);
        traverse(dp, word, w_c+1, s_p, w_c+1, moves+move_f);
        int move_s = move(word, s_p, w_c);
        traverse(dp, word, f_p, w_c+1, w_c+1, moves+move_s);
    }
    int minimumDistance(string word) {
        int n = word.size();
        if(n<=2) return 0;
        vector<vector<int>> dp(n+1,vector<int> (n+1, INT_MAX));
        traverse(dp, word, 0, 0, 0, 0);
        int res = INT_MAX;
        for(int i=0;i<=n;i++) {
            res = min(res, dp[i][n]);
            res = min(res, dp[n][i]);
        }
        return res;
    }
};