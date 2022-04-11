class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> strength(mat.size(),0);
        for(int i=0;i<mat.size();i++) {
            for(int j = 0;j<mat[i].size();j++) {
                if(mat[i][j]==0) {
                    strength[i] = j;
                    break;
                }
                if(mat[i][j]==1 && j==mat[i].size()-1) strength[i] = mat[i].size();
            }
        }
        vector<int> idx;
        for(int i=0;i<mat.size();i++) idx.push_back(i);
        sort(idx.begin(),idx.end(),[&](const auto &a,const auto &b){if(strength[a]==strength[b]){return a < b;} else {
            return strength[a] < strength[b];
        }});
        vector<int> res(idx.begin(),idx.begin()+k);
        return res;
    }
};