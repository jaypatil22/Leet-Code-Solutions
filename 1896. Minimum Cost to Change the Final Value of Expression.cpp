class Node {
    public:
    Node(bool val,char op) {
        this->val = val;
        this->op = op;
        this->cnt[0] = INT_MAX;
        this->cnt[1] = INT_MAX;
    }
    bool val;
    char op;
    int cnt[2];
};

class Solution {
public:
    int minOperationsToFlip(string expression) {
        stack<Node> st;
        vector<Node> post;
        for(int i=0;i<expression.size();i++) {
            if(expression[i] == '(') {
                st.push(Node(0,expression[i]));
            } else if(expression[i]==')') {
                while(!st.empty() && st.top().op!='(') {
                    post.push_back(st.top());
                    st.pop();
                }
                st.pop();
            } else if(expression[i]=='0' || expression[i]=='1') {
                st.push(Node(expression[i]-'0',' '));
            } else {
                while(!st.empty() && st.top().op!='(') {
                    post.push_back(st.top());
                    st.pop();
                }
                st.push(Node(0,expression[i]));
            }
        }
        while(!st.empty()) {
            post.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<post.size();i++) {
            if(post[i].op==' ') {
                if(post[i].val==0) {
                    post[i].cnt[0] = 0;
                    post[i].cnt[1] = 1;
                } else {
                    post[i].cnt[0] = 1;
                    post[i].cnt[1] = 0;
                }
                st.push(post[i]);
            } else if(post[i].op == '|') {
                Node op1 = st.top();
                st.pop();
                Node op0 = st.top();
                st.pop();
                Node newNode(0,' ');
                
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[0]+op0.cnt[0]);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[1]+op0.cnt[0]);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[0]+op0.cnt[1]);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[1]+op0.cnt[1]);
                
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[0]+op0.cnt[0]+1);
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[1]+op0.cnt[0]+1);
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[0]+op0.cnt[1]+1);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[1]+op0.cnt[1]+1);
                
                st.push(newNode);
            } else {
                Node op1 = st.top();
                st.pop();
                Node op0 = st.top();
                st.pop();
                Node newNode(0,' ');
                
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[0]+op0.cnt[0]+1);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[1]+op0.cnt[0]+1);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[0]+op0.cnt[1]+1);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[1]+op0.cnt[1]+1);
                
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[0]+op0.cnt[0]);
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[1]+op0.cnt[0]);
                newNode.cnt[0] = min(newNode.cnt[0],op1.cnt[0]+op0.cnt[1]);
                newNode.cnt[1] = min(newNode.cnt[1],op1.cnt[1]+op0.cnt[1]);
                
                st.push(newNode);
            }
        }
        return max(st.top().cnt[0],st.top().cnt[1]);
    }
};