class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
                int r = st.back();st.pop_back();
                int l = st.back();st.pop_back();
                string a = tokens[i];
                if(a=="+") {
                    st.push_back(l+r);
                } else if(a == "-") {
                    st.push_back(l-r);
                } else if(a == "*") {
                    st.push_back(l*r);
                } else {
                    st.push_back(l/r);
                }
            } else {
                st.push_back(stoi(tokens[i]));
            }
        }
        return st.back();
    }
};