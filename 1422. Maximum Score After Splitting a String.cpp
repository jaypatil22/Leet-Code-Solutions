class Solution {
public:
    int maxScore(string s) {
        vector<int> left(s.size());
        vector<int> right(s.size());

        for(int i=0;i< s.size();i++) {
            if(s[i] == '0') {
                left[i]++;
            } else {
                right[i]++;
            }
        }

        for(int i=1;i<s.size();i++) {
            left[i] += left[i-1];
        }

        for(int i = s.size()-2;i>=0;i--) {
            right[i] += right[i+1];
        }
        int max = 0;
        for(int i =1;i<s.size()-1;i++) {
            if(max < left[i] + right[i])
                max = left[i] + right[i];
        }
        if(left[s.size()-1] == s.size() || right[0] == s.size())
            return s.size()-1;

        return max;
    }
};
