class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b.size() == 0)
            return 0;
        vector<int> prefix(b.size()+1);
        for(int i =1,j=0;i<b.size();) {
            if(b[i] == b[j]) {
                prefix[++i] = ++j;
            } else if(j==0) {
                prefix[++i] = j;
            } else {
                j = prefix[j];
            }
        }
        for(auto i = 0,j=0;i<a.size();i += max(1,j-prefix[j]),j= prefix[j]) {
            while(j<b.size() && a[(i+j)%a.size()] == b[j]) ++j;
            if(j == b.size()) {
                return (i+j -1)/a.size() + 1;
            }
        }
        return -1;
    }
};
