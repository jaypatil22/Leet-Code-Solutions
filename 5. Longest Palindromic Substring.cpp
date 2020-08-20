class Solution {
public:

    int expand(string &s,int l,int r) {
        int left = l-1,right = r+1,count=0;
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;right++;count++;
        }
        return count*2;
    }

    string longestPalindrome(string s) {
        if(s.length() < 1) return "";
        if(s.length() == 1) return s;
        if(s.length() == 2) {
            if(s[0] == s[1])
                return s;
            else
                return s.substr(0,1);
        }
        int start = 0,end=0;
        for(int i =0;i<s.length();i++) {
            int l1 = 1+expand(s,i,i);
            int l2 = s[i] == s[i+1] ? expand(s,i,i+1)+2 : 0;
            int l = l1 < l2 ? l2 : l1;
            if(l > end - start+1) {
                start = i - (l -1)/2;
                end = i + l/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
