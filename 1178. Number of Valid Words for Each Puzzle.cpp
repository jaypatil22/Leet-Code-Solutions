class Solution {
public:
    int mask(string s) {
        int m = 0;
        for(int i=0;i<s.size();i++) {
            m |= 1 << (s[i]-'a');
        }
        return m;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> m;
        vector<int> res(puzzles.size());
        for(int i=0;i<words.size();i++) {
            int ma = mask(words[i]);
            if(m.find(ma)==m.end()) {
                m[ma] = 1;
            } else {
                m[ma]++;
            }
        }
        for(int i=0;i<puzzles.size();i++) {
            int first = 1 << (puzzles[i][0]-'a');
            int sub = mask(puzzles[i].substr(1));
            for(int submask = sub;submask;submask = (submask-1)&sub) {
                res[i] += m[submask | first];
            }
            res[i] += m[first];
        }
        return res;
    }
};