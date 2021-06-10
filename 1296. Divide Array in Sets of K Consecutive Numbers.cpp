class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return false;
        multiset<int> s;
        for(int a : nums) {
            s.insert(a);
        }
        while(!s.empty()) {
            int a = *s.begin();
            int i = a,cnt=1;
            s.erase(s.begin());
            while(s.find(i+1)!=s.end()) {
                i++;cnt++;
                s.erase(s.find(i));
                if(cnt==k) goto next;
            }
            if(cnt%k) return false;
            next : ;
        }
        return true;
    }
};