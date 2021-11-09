class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.size();i++) {
            if(m.find(s[i])==m.end()) m[s[i]] = 1;
            else m[s[i]]++;
        }
        sort(s.begin(),s.end());
        s.erase(unique(s.begin(),s.end()),s.end());
        sort(s.begin(),s.end(),[&](const char &a,const char &b){return m[a] > m[b];});
        string res = "";
        for(char a : s) {
            string b(m[a],a);
            res += b;
        }
        return res;
    }
};