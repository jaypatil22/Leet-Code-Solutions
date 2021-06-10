class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize==1) return true;
        multiset<int> s;
        for(int a : hand) {
            s.insert(a);
        }
        while(!s.empty()) {
            int cnt=1;
            int a = *s.begin();
            int i=a;
            s.erase(s.begin());
            // cout << a << " ";
            while(s.find(i+1)!=s.end()) {
                cnt++;i++;
                // cout << i << " ";
                s.erase(s.find(i));
                if(cnt==groupSize) goto next;
            }
            // cout << endl;
            // cout << cnt << endl;
            if(cnt%groupSize) return false;
            next:;
        }
        return true;
    }
};