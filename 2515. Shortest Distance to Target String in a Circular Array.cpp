class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = INT_MAX;
        for(int i=0;i<words.size();i++) {
            if(words[i]==target) {
                int diff = abs(i-startIndex);
                res = min(res,min(diff, n-diff));
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};