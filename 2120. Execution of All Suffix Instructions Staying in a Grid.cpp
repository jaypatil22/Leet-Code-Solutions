class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        for(int i=0;i<s.size();i++) {
            int row= startPos[0],col=startPos[1],j,cnt = 0;
            for(j=i;j<s.size();j++) {
                if(s[j]=='L') {
                    col--;
                } else if(s[j]=='R') {
                    col++;
                } else if(s[j]=='U') {
                    row--;
                } else {
                    row++;
                }
                if(row<0 || row>=n || col<0 || col>=n) break;
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};