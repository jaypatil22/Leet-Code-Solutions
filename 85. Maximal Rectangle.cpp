class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int m = matrix.size(),n=matrix[0].size();
        vector<int> hist(n,0);
        hist.emplace_back(0);
        int res = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]=='1') {
                    hist[j]+=1;
                } else {
                    hist[j] = 0;
                }
            }
            vector<int> st;
            for(int k=0;k<=n;k++) {
                while(!st.empty() && hist[st.back()]>=hist[k]) {
                    int h = hist[st.back()];
                    st.pop_back();
                    int left = st.empty() ? -1 : st.back();
                    res = max(res, h*(k-left-1));
                }
                st.emplace_back(k);
            }
        }
        return res;
    }
};
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();