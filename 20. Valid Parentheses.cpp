class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // cout << s.size() << "\n";
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if(!st.empty()) {
                char r = st.top();
                if(s[i] == ')') {
                    if(r != '(') {
                       // cout << "1" << "\n";
                        return false;
                    }
                }
                if(s[i] == ']') {
                    if(r != '[') {
                       // cout << "2" << "\n";
                        return false;
                    }
                }
                if(s[i] == '}') {
                    if(r != '{') {
                       // cout << "3" << "\n";
                        return false;
                    }

                }
                st.pop();
            } else {
                return false;
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
