class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int index = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] != ' ') {
                if(index != 0) s[index++] = ' ';
                int j = i;
                while(j<s.size() && s[j] != ' ') s[index++] = s[j++];
                reverse(s.begin()+index-(j-i),s.begin()+index);
                i = j;
            }
        }
        s.erase(s.begin()+index,s.end());
        return s;
    }
};