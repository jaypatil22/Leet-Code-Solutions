class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<=1) return true;
        bool first = toupper(word[0])==word[0] ? true : false;
        bool rest = toupper(word[1])==word[1] ? true : false;
        for(int i=2;i<word.size();i++) {
            bool cur = toupper(word[i])==word[i] ? true : false;
            if(cur != rest) return false;
        }
        if(rest && !first) return false;
        return true;
    }
};