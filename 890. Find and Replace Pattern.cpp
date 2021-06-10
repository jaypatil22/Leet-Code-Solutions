class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,int> pat;
        string patt="";
        int cnt=1;
        for(int i=0;i<pattern.size();i++) {
            if(pat.find(pattern[i])==pat.end()) {
                patt += to_string(cnt);
                pat[pattern[i]] = cnt;
                cnt++;
            } else {
                patt+=to_string(pat[pattern[i]]);
            }
        }
        vector<string> res;
        for(int i=0;i<words.size();i++) {
            if(words[i].size()==pattern.size()) {
                string word="";
                pat.clear();
                cnt=1;
                for(int j=0;j<words[i].size();j++) {
                    if(pat.find(words[i][j])==pat.end()) {
                        word+=to_string(cnt);
                        pat[words[i][j]] = cnt;
                        cnt++;
                    } else {
                        word+= to_string(pat[words[i][j]]);
                    }
                }
                if(patt == word) res.push_back(words[i]);
            }
        }
        return res;
    }
};