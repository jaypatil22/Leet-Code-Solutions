class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n),st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.back()]>=heights[i]) {
                st.pop_back();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.back();
            st.emplace_back(i);
        }
        st.clear();
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && heights[st.back()]>=heights[i]) {
                st.pop_back();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.back();
            st.emplace_back(i);
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            int ar = heights[i]*(right[i]-left[i]-1);
            if(res < ar) res = ar;
        }
        return res;
    }
};
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();