class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> c(26);
        for(int i=0;i<t.size();i++) {
            c[t[i]-'a']++;
        }
        int res=0;
        for(char a :s ) {
            if(c[a-'a']==0){
                res++;
            } else {
                c[a-'a']--;
            }
        }
        return res;
    }
};