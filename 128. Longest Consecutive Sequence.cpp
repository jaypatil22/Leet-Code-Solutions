class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_multiset<int> s;
        for(int a : nums) {
            s.insert(a);
        }
        int res = 0;
        while(!s.empty()) {
            int a = *s.begin();
            s.erase(s.find(a));
            int c = a;
            int h = a;
            int curr = 1;
            while(!s.empty() && s.find(c+1)!=s.end()) {
                curr++;
                c++;
                s.erase(s.find(c));
            }
            while(!s.empty() && s.find(h-1)!=s.end()) {
                curr++;
                h--;
                s.erase(s.find(h));
            }
            if(res < curr) {
                res = curr;
            }
        }
        return res;
    }
};