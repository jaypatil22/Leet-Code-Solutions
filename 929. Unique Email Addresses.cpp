class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(int i=0;i<emails.size();i++) {
            string cur= "";
            bool flag = 1;
            for(int j=0;j<emails[i].size();j++) {
                if(emails[i][j]=='.') continue;
                else if(emails[i][j]=='+') {
                    while(emails[i][j] != '@') {
                        j++;
                    }
                    while(j<emails[i].size()) {
                        cur += emails[i][j];j++;
                    }
                    flag = 0;
                } else if(emails[i][j]=='@') {
                    while(j<emails[i].size()) {
                        cur += emails[i][j];
                        j++;
                    }
                } else {
                    cur += emails[i][j];
                }
            }
            
            s.insert(cur);
        }
        // for(string em : s) cout << em << endl;
        return s.size();
    }
};