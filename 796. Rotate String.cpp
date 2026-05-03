class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++) {
            if(s[i]==goal[0]) {
                int j;
                for(j=1;j<goal.size();j++) {
                    if(goal[j]!=s[(i+j)%s.size()]) break;
                }
                if(j==goal.size()) return true;
            }
        }
        return false;
    }
};