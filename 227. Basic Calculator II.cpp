class Solution {
public:
    bool precedence(char a,char b) {
        if(a=='+' || a=='-') {
            return false;
        } else if(a=='*' || a=='/') {
            if(b=='+' || b=='-') return true;
            else return false;
        }
        return true;
    }
    int eval(int op1,int op2,char op) {
        if(op=='-') {
            return op1-op2;
        } else if(op=='+') {
            return op1+op2;
        } else if(op=='*') {
            return op1*op2;
        } else {
            return op1/op2;
        }
    }
    int calculate(string s) {
        stack<char> st;
        stack<int> op;
        int i=0;
        while(i<s.size()) {
            while(i<s.size() && s[i]==' ') i++;
            string n = "";
            while(i<s.size() && isdigit(s[i])) {
                n += s[i];
                i++;
            }
            if(n!="") op.push(stoi(n));
            if(s[i]=='*' || s[i]=='/' || s[i]=='-' || s[i]=='+') {
                if(st.empty()) {
                    st.push(s[i]);
                    i++;
                }else if(precedence(s[i],st.top())) {
                    st.push(s[i]);
                    i++;
                } else {
                    int op2 = op.top();op.pop();
                    int op1 = op.top();op.pop();
                    op.push(eval(op1,op2,st.top()));
                    st.pop();
                }
            }
            // cout << op.top() << " " << i << " " << (char)st.top() << endl;
        }
        while(!st.empty()) {
            int op2 = op.top();op.pop();
            int op1 = op.top();op.pop();
            op.push(eval(op1,op2,st.top()));
            st.pop();
        }
        return op.top();
    }
};
auto speed = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();