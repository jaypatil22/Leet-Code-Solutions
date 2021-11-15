class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++) {
            while(!st.empty() && temperatures[st.back()] < temperatures[i]) {
                res[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};