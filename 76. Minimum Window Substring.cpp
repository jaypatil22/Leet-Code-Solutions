class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(char a : t) m[a]++;
        int res= INT_MAX,start=0,end=0,counter=t.size(),begin=0;
        while(end<s.size()) {
            if(m[s[end++]]-->0) counter--;
            while(counter==0) {
                if(end-start < res) res= end-(begin=start);
                if(m[s[start++]]++==0) counter++;
            }
        }
        return res==INT_MAX ? "" : s.substr(begin,res);
    }
};