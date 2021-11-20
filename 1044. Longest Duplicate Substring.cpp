class Solution {
public:
    string helper(string &s, int len) {
        long long prime = 31, mod = 19260817, hash = 0, pow = 1;
        for(int i=0;i<len;i++) {
            hash = (((hash*prime)%mod) + (s[i]-'a'))%mod;
            if(i>0) pow = (prime*pow)%mod;
        }
        unordered_map<long long, vector<int>> m;
        m[hash].push_back(0);
        int sp = 0, ep = len;
        while(ep < s.size()) {
            hash = (hash-((pow * (s[sp]-'a'))%mod)+mod)%mod;
            hash  = (((hash*prime)%mod) + (s[ep]-'a'))%mod;
            if(m.find(hash) != m.end()) {
                string curr = s.substr(sp+1,len);
                for(int a : m[hash]) {
                    if(curr == s.substr(a,len)) return curr;
                }
                m[hash].push_back(sp+1);
            } else {
                m[hash].push_back(sp+1);
            }
            sp++,ep++;
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int l = 0, h = s.size();
        string res = "";
        while(l <= h) {
            int m = l + (h-l)/2;
            string flag = helper(s,m);
            // cout << l << " " << h << " " << m << endl;
            if(flag!="") {
                if(res.size() < flag.size()) res = flag;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return res;
    }
};