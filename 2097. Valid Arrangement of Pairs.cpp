class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> m;
        unordered_map<int,int> in, out;
        vector<vector<int>> res;
        for(auto a : pairs) {
            m[a[0]].push_back(a[1]);
            in[a[1]]++;
            out[a[0]]++;
        }
        int start = -1;
        for(auto a : m) {
            if(out[a.first] - in[a.first] == 1) {
                start = a.first;
                break;
            }
        }
        if(start == -1) {
            start = m.begin()->first;
        }
        helper(m,res,start);
        reverse(res.begin(),res.end());
        return res;
    }
    
    void helper(unordered_map<int,vector<int>> &m, vector<vector<int>> &res,int cur) {
        auto& a = m[cur];
        while(!a.empty()) {
            int nei = a.back();
            a.pop_back();
            helper(m,res,nei);
            res.push_back({cur, nei});
        }
    }
};