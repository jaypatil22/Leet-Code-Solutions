class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        unordered_set<int> m;
        stack<int> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                st.push(i);
            } else if(s[i]==')') {
                if(st.empty()) m.insert(i);
                else {
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            m.insert(st.top());
            st.pop();
        } 
        for(int i=0;i<s.size();i++) {
            if(m.find(i)!=m.end()) continue;
            else res += s[i];
        }
        return res;
    }
};