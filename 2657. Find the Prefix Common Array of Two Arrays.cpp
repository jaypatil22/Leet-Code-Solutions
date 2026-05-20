class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> m;
        vector<int> res(n);
        int cur = 0;
        for(int i=0;i<n;i++) {
            m[A[i]]++;
            if(m[A[i]] == 2) cur++;
            m[B[i]]++;
            if(m[B[i]] == 2) cur++;
            res[i] = cur;
        }
        return res;
    }
};