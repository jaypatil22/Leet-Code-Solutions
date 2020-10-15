class Solution {
public:
    bool buddyStrings(string A, string B) {
        int l1 = A.size(),l2= B.size();
        if(l1 != l2)
            return false;
        if(A==B && set<char>(A.begin(),A.end()).size()<A.size()) return true;

        vector<int> diff;
        for(int i =0;i<A.size();i++) if(A[i]!=B[i]) diff.emplace_back(i);
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];

    }
};
