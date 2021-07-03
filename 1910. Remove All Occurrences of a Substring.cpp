class Solution {
public:
    bool check(vector<char> &st,string &part) {
        if(st.size() < part.size()) return false;
        int i=st.size()-1,j=part.size()-1;
        while(j>=0) {
            if(st[i] == part[j]) {
                i--;j--;
            } else {
                return false;
            }
        }
        return true;
    }
    void remove(vector<char> &arr,int i) {
        while(i) {
            arr.pop_back();
            i--;
        }
    }
    string removeOccurrences(string s, string part) {
        vector<char> st;
        for(int i=0;i<s.size();i++) {
            st.push_back(s[i]);
            if(s[i]==part.back()) {
                if(check(st,part)) {
                    remove(st,part.size());
                }
            }
        }
        string res = "";
        for(int i=0;i<st.size();i++) {
            res += st[i];
        }
        return res;
    }
};