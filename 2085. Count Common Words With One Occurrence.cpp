class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> c1,c2;
        for(string &s : words1) {
            c1[s]++;
        }
        for(string &s : words2) {
            c2[s]++;
        }
        int res = 0;
        for(auto a : c1) {
            if(a.second==1 && c2[a.first]==1) res++;
        }
        return res;
    }
};